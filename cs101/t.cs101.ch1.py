"""

A Primer on Scientific Programming with Python 
By: Hans Petter Langtangen 
 
RULES FOR EDITING:

Start and end every chapter with triple-quotes
Ends of chapters should look like:

"""
"""

Separate python code like this:

"""

print("Hello World!")

"""

For now, ignore this:

"""
import builtins
import inspect

def print_with_line(*args, **kwargs):
    # Get the caller's frame
    frame = inspect.currentframe().f_back
    line_no = frame.f_lineno
    # Prepend line number to output
    builtins.print(f"{line_no}:", *args, **kwargs)

# Override built-in print
print = print_with_line

"""

"""
"""

Ch. 1 COMPUTING with Formulas 
We will learn how to write and run a Python program, how to work with variables, how to compute with math functions and how to use Python for calculations 
 

Using a program as a calculator: 
: If v0 = 5 m/s and g = 9.81 m/s^2, we are interested in the time interval [0,1], as t = 0 or t = 2v0/g 
At time t  = 0.6s, we have y = (5 * 0.6) - 0.5(9.81 * 0.6^2) 
We can use python to print the answer: 

""" 

print (5*0.6 - 0.5*9.81*0.6**2) 
 

"""
What is a program? A sequence of instructions to the computer, written in a computer language 
: these languages are far less advanced than English, so to communicate a complex task, it requires very complex instructions 
One of the most difficult things about programming is understanding how a sequence of instructions to a computer can solve a problem 

""" 
"""

1.1.3 Tools for Writing Programs 

- Plain test editor, IDE (integrated development environment) with a text editor, an IPython notebook 

1.1.11 Formatting Text and Numbers

Print statement prints a string, which is enclosed in ' or ". 
The string has various "slots", which are denoted by starting with a %
Next, you list the variables inside parentheses after the string, separated by a % sign.

For example:

"""

v0 = 5
g = 9.81
t = 0.6
y = v0 * t - 0.5 * g * t ** 2
print ('At t=%g s, the height of the ball is %.2f m.' %(t,y))

"""

Here, the %g indicates that the fstring will print as compactly as possible, and the %.2f means a real number written with 2 digits after the decimal. f means a floating-point number, or a real number

%s: a string
%d: an integer
%0xd: an integer in a field of with x, padded with leading zeros
%f: decimal notation with six decimals
%e: compact scientific notation, e in the exponent
%E: compact scientific notation, E in the exponent
%g: compact decimal or scientific notation (with e)
%G: compact decimal or scientific notation (with E)
%xz: format z right-adjusted in a field of width x
%-xz: format z left-adjusted in a field of width x
%.yz: format z with y decimals
%x.yz: format z with y decimals in a field of width x
%%: the percentage sign % itself

Instead of the previous format, another format can be used, called the format string syntax:

"""

print (f"At t={t:g} s, the height of the ball is {y:.2f} m.")

"""

Alternatively, we can use .format(variable1 = <> , variable2 = <>)
Instead of f"".

NEWLINE CHAR
\n signifies a new line.

"""
"""

1.2 Computer Science Glossary

There are important words that programmers use when talking about programming
Here are the ones we don't fully understand yet:
- blanks
- assignment
- code segment, code snippet
- implement, implementation
- library

Code segment or snippet is a collection of consecutive statements from a program
Source code means the text that constitutes a program
An executable is a single file that starts a program when we run it
Library is a collection of generally useful program pieces that can be applied in many different contexts
	: allows for you not to have to code snippets that others have already programmed
	: libraries constitute modules and packages
	-> packages contain multiple modules, which can give you multiple useful functions, such as the math module, which gives access to many standard mathematical functions
	: download from www.python.org/pypi

Programs are built of statements. 
An assignment statement may look like:
v0=3
whereas a print statement looks like:
print y
multiple statements may be written on a line, if separated by a semicolon (;)

Assignments are signified by an = sign
	: right hand side of an assignment is an expression, which is a combo of values, variables, operators

Blanks are insignificant around = or arithmetic operators
	: they are essential for easy reading of a program, and easy reading is essential for debugging
	:1 blank around =, +, and -, but no blanks around *, /, **

All input data must be assigned values in a prgram before the output can be computed

An Operating System, or OS is a collection of programs that manages the hardware and software resources on a computer
	: dominantly Windows, Mac, OS X, and Linux

"""
"""

1.3 Another Formula: Celsius-Fahrenheit Conversion

Let's try to convert temp in celsius to fahrenheit:
F = 9/5 C + 32

"""

C = 21
F = (9/5)*C + 32
print(F)

"""

This works, because python 3 uses float division, not integer division. Other programming languages and earlier versions of python use integer division, which would cause an error
	: This leads us to objects

1.3.2 Objects in Python

When we write:
C = 21
Python assigns it as an integer object holding the value 21. Meanwhile, it recognizes 21.0 as a float object

1.3.3 Avoiding Integer Division

In the case that you want to do the normally undesireable integer division, it is useful to use // which explicitly indicates integer division
In python 2, you can use the package __future__ to import the division module:

from __future__ import division

Here, let's fix the above code:

"""

F = (9.0/5)*C + 32
print("%.2f" %(F))

"""

"""
"""

1.4 Evaluating Standard Mathematical Functions

Example: Using the Sqrt Function
Consider yc = v0t - 0.5gt^2.
How long does it take for the ball to reach the height yc? 

we derive: t1 = v0 - sqrt(v0^2 - 2gyc) / g and t2 = (v0 + sqrt(v0^2 - 2gyc)) / g

"""

v0 = 5
g = 9.81
yc = 0.2
import math
t1 = (v0 - math.sqrt(v0**2 - 2*g*yc)); t2 = (v0 + math.sqrt(v0**2 - 2*g*yc))
print ("At %g s and %g s, the height is %g m." %(t1, t2, yc))

"""

Although people like to use math.sqrt(), it is often incovenient and tedious, so it is preffered, at times to import sqrt from math with this alternate syntax:

from math import sqrt

:We can now just say sqrt()

:OR we can change the name of the module we are referring to by doing this:

import math as m

:So now we can write something like m.sqrt()
In python, everything is an object, and variables simply refer to objects. New varaibles can refer to modules and functions as objects. 

1.4.2 Example: Computing with sinh(x)

sinh(x) = 0.5*(e**x - e**-x)

"""

import math as m
x = 2*m.pi
r1 = m.sinh(x)
r2 = 0.5*(m.exp(x) - m.exp(-x))
r3 = 0.5*(m.e**x - m.e**-x)
print(r1,r2,r3)

"""

Here, we face a rounding error. Floating-point math operation most of the time round

"""
"""

1.5 Interactive Computing

Python has the ability to execute statements and evaluate expressions interactively

1.5.3 IPython

Stay in IPython when doing ECE or CS work, trust me, the debugger is a lot more helpful than the one on just python3

"""
"""

1.6 Complex Numbers

- The imaginary number i is written as j in python
- The numerical python package has functions that return a float object if the result is real and a complex object if the result is a complex number

We can call it using:

from numpy.lib.scimath import *

"""

from scipy import *
from cmath import sqrt
print(sqrt(4))
print(sqrt(-4))
print(2)

"""

"""
"""

1.7 Symbolic Computing

PYthon has a package SymPy for symbolic computing, such as exact integration, differentiation, equation solving, and expansion of taylor series

1.71 Basic Differentiation and Integration

"""

from sympy import (
	symbols,
	diff,
	integrate,
	Rational,
	lambdify,
	)
t, v0, g = symbols('t v0 g')
y = v0*t - Rational(1,2)*g*t**2
dydt = diff(y,t)
print(dydt)
intofdy = integrate(dydt,t)
print(intofdy)

"""

We can use the display fn from SymPy to simplify expressions:

"""

import sympy as sp
from IPython.display import display
x,y,z = sp.symbols("x,y,z")
a = x*x*y*x*z*z*x*y
result = (display(a))

"""

We can also use trig functions:
sin, cos, tan 

We can also evaluate expressions by using evalf from SymPy

1.7.2 Equation Solving

You can use the solve function from sympy 

solve(e,t)
where e is normally the function name and t is the unknown


1.7.3 Taylor Series and More 

Use the .series method to expand a function to its taylor series counterpart

"""

from sympy import latex, exp, sin, cos
f = exp(t)
print(latex(f.series(t, 0, 7)))


