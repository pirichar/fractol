#! /bin/bash

printf "\n\n\e[1;94m------TESTING minilibx.c------\e[0m\n\n"
gcc -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit  ./src/*.c 
./a.out