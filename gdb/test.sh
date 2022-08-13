#!/usr/bin/env bash

if [ "$1" == "--restore" ]
then
    printf "Moechten Sie wirklich alle Dateien mit den Originaldateien ueberschreiben?\n"
    printf "Dieser Schritt kann nicht rueckgaengig gemacht werden!\n"
    printf "Do you really want to replace every file with its original version?\n"
    printf "This step is non reversable!\n"
    printf "y/n? "
    read -n1 answer
    if [ $answer == "y" ]
    then
        cp original/* .
        printf "\nDateien kopiert.\n"
        exit 0
    else
        printf "\nAbgebrochen.\n"
        exit 1
    fi
fi

if ! make buggy
then
    printf "ERROR: Das Programm kompiliert nicht!\n"
    exit 1
else
    printf "OK: Kompiliert.\n\n"
fi

if ! ./buggy
then
    printf "ERROR: Das Programm stuerzt ab!\n"
    exit 1
else
    printf "OK: Das Programm laeuft durch.\n\n"
fi

if ! sha1sum -c checksums
then
    printf "ERROR: Die Originaldateien wurden veraendert\n"
    exit 1
else
    printf "OK: Pruefsummen validiert.\n\n"
fi

if ! ./diff.py
then
    printf "ERROR: Es wurden zu viele Zeichen geaendert\n" 
    exit 1
else
    printf "OK: Maximal 1 Zeichen geaendert.\n\n"
fi


