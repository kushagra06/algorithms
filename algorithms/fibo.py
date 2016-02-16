#!/usr/bin/python

def fib(n):
    if n<=2:
        return 1
    else:
        return fib(n-1)+fib(n-2)

n=input()
x=fib(n)
print x
