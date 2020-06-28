#!/usr/bin/env bash

project_dir=$(dirname "$0")
cd "$(dirname "${project_dir}")" || exit

gcc -Wall snippet.c -o snippet

./snippet