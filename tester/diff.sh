#!/bin/bash
make re -C ../
clang main.c ../libftprintf.a -o ft_printf.out
clang real.c ../libftprintf.a -o real.out
./ft_printf.out > custom_result.txt
./real.out > real_result.txt
diff custom_result.txt real_result.txt
