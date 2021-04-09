#!/usr/bin/env bash

project_dir=$(dirname "$0")
cd "$(dirname "${project_dir}")" || exit

shopt -s extglob

rm -rv !(".gitignore"|"clean.sh"|"main.c")
