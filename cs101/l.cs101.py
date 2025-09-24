"""

Lecture 6.1: Sympy

Use case 1: Working with fns

We can do derivatives and integrals using Sympy:

"""

import math as m
import sympy as sp
from IPython.display import display

x, y = sp.symbols("x,y")
f = sp.sin(x) * x**2 - 10 * x
display(f)
display(sp.diff(f))
display(sp.integrate(f))

