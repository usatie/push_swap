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

echo "[Bonus OK Cases]"
printf 'printf "%s" | ./checker 3 2 1\n' "sa\nrra\n"
printf "sa\nrra\n" | ./checker 3 2 1 >.ok.tmp
printf "OK\n" | diff -U 3 - .ok.tmp && printf "\e[32mPrinted OK correctly\n\e[m" || printf "\e[31mDiff Erorr\n\e[m"
rm .ok.tmp

echo "[Bonus KO Cases]"
printf 'printf "%s" | ./checker 3 2 1\n' "pb\npa\n"
printf "pb\npa\n" | ./checker 3 2 1 >.ko.tmp
printf "KO\n" | diff -U 3 - .ko.tmp && printf "\e[32mPrinted KO correctly\n\e[m" || printf "\e[31mDiff Erorr\n\e[m"
rm .ko.tmp

