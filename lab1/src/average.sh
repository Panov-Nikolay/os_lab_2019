#!/bin/sh

sum=0
count=$#

if [ "$count" -eq 0 ]; then
    echo "Нет аргументов"
    exit 1
fi
for number in $@; do
    sum=$((sum + number))
done
average=$((sum / count))
echo "Количество аргументов: $count"
echo "Среднее арифметическое: $average"