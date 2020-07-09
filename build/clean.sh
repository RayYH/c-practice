#!/usr/bin/env bash

project_dir=$(dirname "$0")
cd "$(dirname "${project_dir}")" || exit

rm -rv !(".gitkeep"|"clean.sh")
