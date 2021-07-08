#!/bin/sh

DIST=$(awk -F'=' '/^ID=/ {print tolower($2)}' /etc/*-release)

if [ $DIST = 'arch' ];
then
	sudo pacman -S libpqxx
fi

# TODO: add other distros


