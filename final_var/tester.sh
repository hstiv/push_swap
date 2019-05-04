#!/usr/bin/env bash
#A STACK WITH 100 RANDOM NUMBERS

ARG100="17 9 93 80 99 2 5 51 84 4 57 48 14 29 55 35 74 21 94 60 68 63 1 92 23 82 12 67 69 98 52 19 83 97 78 39 75 100 25 24 8 7 41 11 86 44 36 72 18 73 16 64 47 90 65 87 77 59 61 45 30 53 54 66 76 28 37 95 70 91 27 6 50 43 81 3 46 13 31 89 88 96 38 62 33 10 15 79 20 42 40 85 26 34 71 49 32 22 58 56";

#A STACK WITH  10 RANDOM NUMBERS.

ARG001=`ruby -e "puts (-50 .. 50).to_a.shuffle.join(' ')"`

ARG10="33 4 5 9 65 2 1 99 40 92 24 55 64 88 76 56 45 4555"

ARG6="2 1 3 6 5 8"

ARG3="2 1 3"

ARG11="1 2 3 4 5 6 7 8 9 10"

#RETURNS COUNT OF OPERATIONS IT TOOK TO SORT DEPENDING ON THE ARG.

./push_swap $ARG001 | wc -l

#TAKES OPERATIONS PRODUCED BY PUSH_SWAP TO CHECKER AND DISPLAYS OK IF SORTED & KO IF NOT.

#time ./push_swap $ARG001 | ./checker $ARG001

#valgrind ./push_swap --leak-check=full $ARG001

#"I WROTE A STUPID ALGO IT WORKS BUT NOT EFFICIENT" - Tshilidzi Tshivhula

#DON'T BE STUPID USE THE CORRECT STACK WHEN TESTING TO AVOID UNEXPECTED BEHAVIOUR
