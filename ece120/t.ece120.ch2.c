"""

Chapter 2: Combinational Logic Design

"""
"""

2.1 Introduction

A circuit is a network that processes discrete-valued variables in digital electronics.

- It may be viewed as a black box with input terminals, output terminals that both yield discrete-valued variables, a functional specification describing relationship between inputs and ouputs and timing specification describing the delay between inputs changing and outputs responding

- Circuits are composed of nodes and elements
	: looking into the black box, we see how circuits are composed of nodes and elements
	: an element is a circuit with inputs, outputs, and a specification
	: a node is a wire whose voltage conveys a discretee-valued varaible
	-> nodes are input, output or internal.

- Digital Circuits are classified as combinational or sequential
	: a combinational circuit's outputs depend on the current values of the inputs
	-> a logic gate is a combinational circuit. It takes in the current input and gives a discrete output

	-> a sequential circuit depends on both current and previous values to compute output	
		: depends on the input sequence (eg. 00101011101)
		: has memory to store what was given as a sequence

- A circuit element is combinational if:
	: Every circuit element is itself combinational
	: Every node is either designated as an input to the circuit or connects to exactly one output terminal of a circuit element
	: No cyclic paths, every path visits each circuit node at most once

- For the sake of VIM, we will use "~" instead of the lineovervar.

"""
"""

2.2 Boolean Equations

The commplement is its inverse: A, vs lineoverA

- A literal: a variable or its complement, in other words, a variable in general
- Product or implicant: the AND of one or more literals
	: eg. AB, lineoverA*lineoverB, ABC

- minterm: a product involving all of the inputs to a function
	: eg. ABC is a minterm for a fn with variables A, B, C

- maxterm: a sum involving all the inputs of a function

Order of operations for Boolean Equations:
	- Not has the highest precendence, then AND (mutliplication), then OR.
	- Products are performed before sums, like PEMDAS

2.2.2 Sum-of-Products Form

A truth table of N inputs has 2^N rows, since there are only 2 options: 1,0.

- Each row is associated with a minterm that is TRUE for that row.
**This has nothing to do with the value of Y. It is simply stating that there is some minterm of combination A, ~A, B, ~B for every truth table that results TRUE.

eg. 

A	B	Y	minterm
0	0	0	(~A)(~B)
0	1	1	(~A)(B)
1	0	0	A(~B)
1	1	0	AB

We can write a Boolean Equation for any truth table by summing each of the minterms for which the output, Y, is TRUE.
	: In the above example, the second row's minterm + 0 is the equation, as it yields TRUE for Y. 

- Sum-of-products canoncial form of a function: The Boolean Equation that is the sum of minterms
	: we add the minterms in the same order that they appear in the truth table, so we always write the same expression for the same truth table.

2.2.3 Product-of-Sums Form

Product-of-Sums Canonical Form
- each row is associated with a maxterm that is FALSE for that row

eg. 
A	B	C	Y	maxterm
0	0	0	1	A + B + C
0	0	1	0	A + B + ~C
0	1	0	0	A = ~B + C
2.2.3 Product-of-Sums Form

Product-of-Sums Canonical Form
- each row is associated with a maxterm that is FALSE for that row

eg. 
A	B	C	Y	maxterm
0	0	0	1	A + B + C
0	0	1	0	A + B + ~C
0	1	0	0	A = ~B + C
2.2.3 Product-of-Sums Form

Product-of-Sums Canonical Form
- each row is associated with a maxterm that is FALSE for that row

eg. 
A	B	C	Y	maxterm
0	0	0	1	A + B + C
0	0	1	0	A + B + ~C
0	1	0	0	A + ~B + C
0	1	1	0	A + ~B + ~C
1	0	0	1	~A + B + C
1	0	1	1	~A + B + ~C
1	1	0	0	~A + ~B + C	
1	1	1	1	~A + ~B + ~C

So look at rows 102, 103.
These result in 0, so we mutliply the maxterms to get a product of sums:
(A + B + ~C)(A + ~B + C)(A + ~B + ~C)(~A + ~B + ~C)

Sum of products prduces the shortest equations when the output is mostly FALSE, and product of sums produces the shortest output when the output is mostly TRUE.


2.3 Boolean Algebra

An expression from POS or SOP doesn't produce the simplest combination of logic gates, they can be simplified with the rules of boolean algebra
- Boolean algebra is based on a set of axioms, IOW, statements that are assumed to be true, but cannot be proved.

Axiom			Dual			Name
B = 0 if B !=1		B = 1 if B != 0		Binary field
~0 = 1			~1 = 0			NOT
0 * 0 = 0		1 + 1 = 1		AND/OR
1 * 1 = 1		0 + 0 = 0		AND/OR
0 * 1 = 1 * 0 = 0	1 + 0 = 0 + 1 = 1 	AND/OR

- Axioms and theorems of Boolean algebra obey the principle of duality
	: * can be interchanged with AND, and + can be interchanged with OR

2.3.2 Theorems of One Variable

Theorem			Dual			Name
B * 1 = B		B + 0 = B		Identity
B * 0 = 0		B + 1 = 1		Null Element
B * B = B		B + B = B		Idempotency
~~B = B 					Involution
B * ~B = 0		B + ~B = 1		Complements

2.3.3 Theorems of Several Variables

Theorem 				Dual				Name
B * C = C * B				B + C = C + B			Commutativity
(B * C) * D = B * (C * D)		(B+C) + D = B + (C + D)		Associativity
(B * C) + (B * D) =  B * (C + D)	(B+C) * (B +D) = B + (C * D)	Distributivity
B * (B + C) = B				B + (B * C) = B			Covering
(B * C) + (B * ~C) = B			(B + C) * (B + ~C) = B		Combining
(B*C) + (~B*D) + (C*D) = B*C + ~B*D	(B+C) * (~B+D) * (C+D) = (B+C) * (~B+D)	Consensus
~(B0 * B1 * ...) = (~B0 + ~B1 + ...) 	~(B0 + B1 + ...) = (~B0 * ~B1 *  ~B2)	Demorgan's Theorem

- See notebook for explanation why on De Morgan's Thm.

- According to De Morgan's therem, NAND = ~inputs of OR, and NOR = ~ inputs of AND	
