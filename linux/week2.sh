#!/bin/bash

# task 1

# awk -F',' '{print $1,$2}' data/employees.txt

# task 2

# awk -F',' '{if ($2 == "Engineering") { print } }' data/employees.txt

# task 3

# awk -F',' '{print $1 " gross pay: $" $3*$4 }' data/employees.txt

# task 4

# awk -F',' 'BEGIN {count = 0} {count++; print count, "(" NF, "fields):", $0}' data/employees.txt

# task 5

awk -F',' 'BEGIN {totalSalary = 0} {if ($2 == "Engineering") {totalSalary += $3 * $4}} END {print "Total Engineering Payroll: ", "$" totalSalary}' data/employees.txt