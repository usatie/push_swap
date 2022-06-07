#!/bin/bash
echo "[Tests using shell script]"
for i in {0..10}
do
	ARG="$(jot 100 0 | sort -R | tr '\n' ' ')"; ./push_swap $ARG | ./checker && printf "[$i] success\n" || printf "[$i] error ARG=[$ARG]\n"
done

echo "[Tests using nafuka11 tester]"
[ ! -d push_swap_tester ] && git clone https://github.com/nafuka11/push_swap_tester.git || echo "push_swap_tester is already cloned."

cd push_swap_tester
python3 push_swap_tester.py -l 5
python3 push_swap_tester.py -l 100
python3 push_swap_tester.py -l 500
