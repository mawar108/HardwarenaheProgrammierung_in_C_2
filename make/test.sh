#!/usr/bin/env bash

filenames='game/game.h monster/monster.h player/player.h sound/sound.h texture/texture.h'

# Delete comments from files
for filename in ${filenames}
do
    sed -i '/^\/\//d' "$filename"
done

# Check if files except for Makefile and game.h were changed
if sha256sum -c 'pruefsummen.txt'
then
    printf '\tOK: Testdateien wurden nicht modifiziert.\n\n'
else
    printf '\./tFEHLER: Eine oder mehrere Testdateien wurden modifiziert.\n\n'
    exit 1
fi

# Check if "make" was used
if grep -q 'make' Makefile
then
    printf "FEHLER: In der Makefile steht 'make'!\n"
    printf "        In einer Makefile darf nicht 'make Regelname' benutzt werden!\n"
    exit 1
fi

if ! make all
then
    printf 'FEHLER: Der Befehl "make all" schlug fehl.\n'
    exit 1
fi

filenames='game.o sound.o texture.o player.o monster.o main.o main'

# Check if files have been created
for filename in ${filenames}
do
    if [ -f "$filename" ]
    then
        printf 'OK: Datei "%s" wurde erstellt.\n' "$filename"
    else
        printf 'FEHLER: Datei "%s" wurde nicht erstellt.\n' "$filename"
        exit 1
    fi
done

# Produce output
if ./main > ausgabe.txt
then
    printf 'OK: Die Datei ausgabe.txt wurde erzeugt.\n'
else
    printf 'FEHLER: Das Programm "main" konnte nicht ausgeführt werden.\n'
    exit 1
fi

# Check if output is as expected
if diff -q ausgabe.txt erwartete_ausgabe.txt
then
    printf 'OK: Die Ausgabe stimmt mit der erwarteten Ausgabe überein.\n'
else
    printf 'FEHLER: Die Datei "ausgabe.txt" stimmt nicht mit der erwarteten Ausgabe in Datei "erwartete_ausgabe.txt" überein:\n'
    diff -y ausgabe.txt erwartete_ausgabe.txt
    exit 1
fi

# Write file modification dates to files so we can change them later for changes
for filename in ${filenames}
do
    stat -c %y "$filename" > "change1_$filename.txt"
done

# Check if some files changed, i.e. their modification date changed.
function check_change() {
    for filename in ${1}
    do
        stat -c %y "$filename" > "change2_$filename.txt"
        if diff "change1_$filename.txt" "change2_$filename.txt" > /dev/null
        then
            printf 'FEHLER: Datei "%s" hat sich nicht geändert, obwohl eine Abhängigkeit geändert wurde.\n' "$filename"
            exit 1
        else
            printf 'OK: Datei "%s" hat sich geändert.\n' "$filename"
        fi
    done
}

# Check if some files stayed the same, i.e. their modification date has not changed.
function check_no_change() {
    for filename in ${1}
    do
        stat -c %y "$filename" > "change2_$filename.txt"
        if diff "change1_$filename.txt" "change2_$filename.txt" > /dev/null
        then
            printf 'OK: Datei "%s" hat sich nicht geändert.\n' "$filename"
        else
            printf 'FEHLER: Datei "%s" hat sich geändert, obwohl keine Abhängigkeit geändert wurde.\n' "$filename"
            exit 1
        fi
    done
}

printf 'INFO: "make all" wird nochmals ausgeführt.\n'

if ! make all
then
    printf 'FEHLER: Der Befehl "make all" schlug fehl.\n'
    exit 1
fi

# Check if all files stayed the same
check_no_change "$filenames"

printf 'INFO: Datei "game.h" wird verändert und "make all" wird nochmals ausgeführt.\n'
# Append comment to "game.h"
printf '//game.h wurde durch diesen Kommentar verändert.\n' >> game/game.h

if ! make all
then
    printf 'FEHLER: Der Befehl "make all" schlug fehl.\n'
    exit 1
fi

# Check if some files stayed the same
check_no_change 'sound.o player.o monster.o texture.o'
# Check if some files changed
check_change 'game.o main.o main'

printf 'INFO: Datei "sound.h" wird verändert und "make all" wird nochmals ausgeführt.\n'
# Append comment to "sound.h"
printf '//sound.h wurde durch diesen Kommentar verändert.\n' >> sound/sound.h

if ! make all
then
    printf 'FEHLER: Der Befehl "make all" schlug fehl.\n'
    exit 1
fi

# Check if some files stayed the same
check_no_change 'player.o monster.o texture.o'
# Check if some files changed
check_change 'sound.o game.o main.o main'


printf 'INFO: Datei "monster.h" wird verändert und "make all" wird nochmals ausgeführt.\n'
# Append comment to "monster.h"
printf '//monster.h wurde durch diesen Kommentar verändert.\n' >> monster/monster.h

if ! make all
then
    printf 'FEHLER: Der Befehl "make all" schlug fehl.\n'
    exit 1
fi

# Check if some files stayed the same
check_no_change 'player.o texture.o'
# Check if some files changed
check_change 'sound.o monster.o game.o main.o main'

printf 'INFO: Datei "player.h" wird verändert und "make all" wird nochmals ausgeführt.\n'
# Append comment to "player.h"
printf '//player.h wurde durch diesen Kommentar verändert.\n' >> player/player.h

if ! make all
then
    printf 'FEHLER: Der Befehl "make all" schlug fehl.\n'
    exit 1
fi

# Check if some files stayed the same
check_no_change 'texture.o'
# Check if some files changed
check_change 'sound.o monster.o player.o game.o main.o main'

printf 'INFO: Datei "texture.h" wird verändert und "make all" wird nochmals ausgeführt.\n'
# Append comment to "texture.h"
printf '//texture.h wurde durch diesen Kommentar verändert.\n' >> texture/texture.h

if ! make all
then
    printf 'FEHLER: Der Befehl "make all" schlug fehl.\n'
    exit 1
fi

# Check if some files changed
check_change 'sound.o monster.o player.o game.o texture.o main.o main'


# Cleanup test files
rm -f ausgabe.txt
for filename in ${filenames}
do
    rm -f "change1_$filename.txt"
    rm -f "change2_$filename.txt"
done

printf 'INFO: "make clean" wird ausgeführt.\n'

make clean

# Check if files have been removed
for filename in ${filenames}
do
    if test -f "$filename"
    then
        printf 'FEHLER: Datei "%s" wurde nicht durch "make clean" entfernt.\n' "$filename"
        exit 1
    else
        printf 'OK: Datei "%s" wurde durch "make clean" entfernt.\n' "$filename"
    fi
done
