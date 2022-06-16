#!/bin/bash
echo "[Bonus Invalid Arguments]"
ARGS=("3 2 1 a" "3 2 1 0a" "3 2 1 2147483648" "3 2 1 -2147483649" "3 2 1 2")
for ARG in "${ARGS[@]}"
do
	printf "./checker $ARG\n"
	./checker $ARG 2>.error.tmp && printf "\e[31mShould prlint Error\n\e[m"
	printf "Error\n" | diff -U 3 - .error.tmp && printf "\e[32mPrinted Error correctly\n\e[m" || printf "\e[31mDiff Erorr\n\e[m"
	rm .error.tmp
done

echo "[Bonus Invalid Instructions]"
ARGS=("\n" "pa\npb" "pa\npb\npp\n")
for ARG in "${ARGS[@]}"
do
	printf 'printf "%s" | ./checker 3 2 1\n' $ARG
	printf "$ARG" | ./checker 3 2 1 2>.error.tmp && printf "\e[31mShould prlint Error\n\e[m"
	printf "Error\n" | diff -U 3 - .error.tmp && printf "\e[32mPrinted Error correctly\n\e[m" || printf "\e[31mDiff Erorr\n\e[m"
	rm .error.tmp
done
