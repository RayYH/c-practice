# C Practice

Some code written in C which may be terrible and buggy, **USE AT YOUR OWN RISK.**

## Build

```bash
# optional: you can use Docker to run a container if you are on windows
$ docker-compose up -d
$ docker exec -it c-practice /bin/bash

$ cd build && cmake ..
$ make

# or, use gcc directly - avoid polluting `src` dir
$ cp -r src/* playground
$ cd playground
# do something (e.g. gcc main.c -o main && ./main)
```

## License

This work is open-sourced and licensed under the [MIT license](LICENSE).
