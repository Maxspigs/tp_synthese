#!/bin/bash
# Commande pour compiler un programme c++
# Veuillez choisir la bonne commande selon votre configuration
#g++ --std=c++11 -o tp03 *.cpp #  <---------------- UBUNTU
g++ -o start main.cpp noeud.cpp  #<--------------------- Mint / Cygwin

sleep 1
./start

exit 0