#!/bin/sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

[ ! -d push_swap_tester ] && git clone https://github.com/nafuka11/push_swap_tester || echo "push_swap_tester is already cloned."
cd push_swap_tester
python3 push_swap_tester.py -l 100
