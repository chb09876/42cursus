#!/bin/bash
check=();
values=();
maxnum=100;
if [[ $# -eq 1 ]];
then
	maxnum=$1;
fi
for ((i = 0; i < $maxnum; i++));
do
	idx=$RANDOM;
	while [[ ${check[idx]} -eq 1 ]];
	do
		idx=$RANDOM;
	done
	values[$idx]=$i;
	check[$idx]=1;
done
echo "${values[@]}";