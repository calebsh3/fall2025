

"""

Chapter 2: Loops and Lists

2.1 While Loop

"""

i = -20
while i<40:
	f = 9*i/5 + 32
	print(i, "    ", end="")
	print(f)
	i = i+5

"""

2.1.2 While Loops

While loops can be used to repeat a set of statements as long as a condition is true

2.1.3 Boolean Expressions

==, !=, >=, >, <

These can be used as conditions in while loops, as well as any expression that has a boolean value

while x > 0 and y <=1:
		print x,y

this statement is the same as saying: 
repeat the following function if,
x (for example 01001101) > 00000000 returns 1 if true, y <=1 returns 1 if true. If both are 1, 1 AND 1 = 1. So returning 1 means it would run.  

"""
"""

Loop Implementation of a Sum

*** SWITCH TO OPENSTAX NOTES FROM PRAIRELEARN ***

Chapter 5: Loops


Loops are blocks of code that run a set of statements while a condition is true
	: often perform a repeated task

2 types of loop introduced in ch. 5: for, while
- Break and Continue statements -> control loop's execution

5.1 While Loop

Runs a set of statements (loop body) as long as  a loop expression (condition), is true
	: if true, the body will execute at least once more
	: if false, the loop's execution will terminate and the next statement after the body will execute

Counting with a while loop:
- A counter variable can be used in the loop expression to determine the number of iterations executed

5.2 For Loops

Container: A list-like object. Can be a range of numbers, a string, or list of values. To access values in a container, a loop can be designed to retrieve objects in the container one at a time

range function: returns a list of integers
range(0,2) returns [0,1,2]. 
range(0, 9, 3) returns [0, 3, 6, 9].

5.3 Nested Loops

Has one or more loops within another loop

Practice:

"""
a_0 = 0
a = 10
while a_0 < 10:
    for i in range(1,a):
        print(i, end=" ")
    a = a - 1
    a_0 += 1
    print("\n")

5.4 Break and Continue

A break statement is used within a for or a while loop to allow the program execution to exit the loop once a condition is triggered
 - for nested loops, break will only break out of the inner loop its in, and not the outer loop
	: better wording -> breaks out of the loop body its a part of

Continue
- Can be used to skip the execution of the remainder of a loop without exiting the loop entirely
