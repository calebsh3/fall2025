import math as m
import sympy as sp

fn, v_0, g, x, theta, y_0 = sp.symbols("fn, v_0, g, x, theta, y_0")

fn = x*sp.tan(theta) - (g*x**2)/(2*v_0**2*(sp.cos(theta))**2)

print(fn)

#exercise 1:
result = 1 + 1
print(result)

#exercise 2:
print("Hello World!")

#exercise 3:

seconds = 7000000000
years = seconds/(60*60*24*365)
print(years)


