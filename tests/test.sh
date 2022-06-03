#!/bin/bash
[ ! -d push_swap_tester ] && git clone https://github.com/nafuka11/push_swap_tester.git || echo "push_swap_tester is already cloned."

cd push_swap_tester
python3 push_swap_tester.py -l 5
python3 push_swap_tester.py -l 100
python3 push_swap_tester.py -l 500
