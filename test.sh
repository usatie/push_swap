#!/bin/bash

echo "[Invalid Cases]"
ARGS=("2 2" "a" "2a" "-2147483649" "2147483648")
for ARG in "${ARGS[@]}"
do
	printf "./push_swap $ARG\n"
	eval "./push_swap $ARG" && printf "\e[31mShould be error\n\e[m" || printf "\e[32mOK\n\e[m"
done

echo "[Valid Cases with no output]"
ARGS=("2" "-2147483648" "2147483647" "1 2 3 4 5")
for ARG in "${ARGS[@]}"
do
	printf "./push_swap $ARG\n"
	eval "./push_swap $ARG" | awk '{printf "\033[31mUnnecessary outputs\033[m"} END {if (NR == 0) printf "\033[32mOK\n\033[m"}' || printf "\e[31mSome Error\n\e[m"
done

echo "[Valid Cases]"
for i in {0..10}
do
	ARG="$(jot 100 -100 100 | sort -uR | head -100 | tr '\n' ' ')"
	printf "[$i] ./push_swap $ARG\n"
	./push_swap $ARG | ./checker $ARG && printf "\e[32mOK\n\e[m" || printf "\e[31mKO\n\e[m"
done

echo "[Tests using nafuka11 tester]"
[ ! -d push_swap_tester ] && git clone https://github.com/nafuka11/push_swap_tester.git || echo "push_swap_tester is already cloned."

cd push_swap_tester
echo "Max result must be <= 3"
python3 push_swap_tester.py -l 3
echo "Max result must be <= 12"
python3 push_swap_tester.py -l 5
echo "Max result must be < 1500(700)"
python3 push_swap_tester.py -l 100
echo "Max result must be < 11500(5500)"
python3 push_swap_tester.py -l 500
