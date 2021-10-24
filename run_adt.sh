#!/bin/bash
#
# Script ini digunakan untuk menjalankan sebuah ADT dari drivernya
#
# Contoh Pakai :
# run_adt.sh pcolor

ADT_NAME=$1

if [[ $ADT_NAME == "" ]] 
then
  printf "\x1b[7m\033[38;2;214;36;36m Error \033[0m\n"
  echo "Nama ADT belum diinput."
  echo
  echo "Gunakan :"
  echo "./run_adt.sh <Nama ADT>"
  echo
  echo "Contoh : ./run_adt.sh pcolor"
  exit
fi

MAIN_FILE=$(find src -name main_$ADT_NAME.c | head -n 1)

if [[ $MAIN_FILE == "" ]]
then 
  printf "\x1b[7m\033[38;2;214;36;36m Error \033[0m\n"
  echo "Main point ADT $1 tidak ditemukan."
else
  make clean
  make main_builder/$MAIN_FILE
  mv ./bin/ADT_RUNNER ./bin/$ADT_NAME

  ./bin/$ADT_NAME
  echo
fi