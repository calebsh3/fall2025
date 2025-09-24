

Digital Design and Computer Architecture
By: David Harris

Ch. 1: From Zero to One

1.1 Microprocessors are key
Goal of the textbook is to learn how to design and build your own microprocessor
Digital Systems: Operate on 1’s and 0’s
: Include logic gates that accept 1,0 and output 1,0 and includes combinations of logic gates to create modules such as adders and memories
: When we learn how to program in assembly, we can give the microprocessor the instructions on how to operate

1.2 Abstraction
Since the building blocks are simple: 1’s, 0’s, and we create complex results, microprocessors are complex
Abstraction: Hide details when they aren’t important
: ex. Politics abstracts the entire world into continents, countries, states, towns, etc. 
: We must abstract digital systems into smaller parts
: Levels of Abstraction regarding Digital Systems
Application Software
OS
Architecture (Instructions, Registers)
Microarchitecture (Datapaths, Controllers)
Logic (Adders, Memories)
Digital Circuits (AND, NOT gates)
Analog Circuits (Amplifiers, Filters)
Devices (Transistors, Diodes)
Physics (Electrons)
	: We must be able to pick the level of abstraction appropriate to solving the problem at hand and evaluate the impact on other levels of abstraction
Discipline: Restricting design choices so that you can work more productively at a higher level of abstraction
: ex. Flintlock rifle -> interchangeable parts as a part of the rifle as a whole allow for rifles to be created much faster with less skill, as there was a standard which allowed repetition and therefore trainability
: in ECE, digital circuits are a subset of analog circuits, which have a fixed voltage. Digital Circuits are much more simple to design (think of digital circuits like the mass produced version of analog circuits).
	-> we can combine components of digital circuits to ultimately outperform ones built from analog components 
	- The 3 Y’s to manage complexity: 
	: Hierarchy → Divide system into modules
	: Modularity → “Well-defined function and interface”, Modules must be easy to connect together for compatibility
	: Regularity → Uniformity among modules, so less designing must be done

1.3 The Digital Abstraction
Digital systems represent information with discrete (discrete means distinct)-valued variables that are not continuous (continuous meaning constant or the same)
Charles Babbage’s Analytical Engine: used gears with 10 positions labeled 0-9 trying to build a mechanical computer
	: Each row processes 1 digit, there are 25 rows of gears, so the machine has 25-digit precision
	: The machine used 0-9, so D= log2(10) bits / gear, or 3.322 bits/gear 
	: the amount of info (D) in a discrete valued variable with N distinct states is measured in units of bits as D=log2N bits
	: ex. Variable with 8 bits: 8 bits of information: 8 = log2N, N = 256, so there are 256 distinct states that could be represented with 8 bits of information
	** It is about how many distinct states can be represented with how much information
	→ Vice Versa to above: a binary variable has 2 distinct states: 0,1: log2(2) = 1. So only 1 bit of information is needed to convey the 2 states
	**BIT = Binary Digit
Boolean Logic: Each variable could be TRUE or FALSE, or ‘1’ as a positive voltage and ‘0’ as a 0 voltage

1.4 Number Systems
In digital systems, binary or hexadecimal are often more convenient than decimal number system
An N-digit decimal number represents 1 of 10^N possibilities
Bits can be 0 or 1, and are joined together to form binary numbers
8 bits = 1 byte, with 2^8 possibilities 
A half byte is called a nibble with 2^4 = 16 possibilities
Microprocessors handle data in words
: the size of a word depends on microprocessor architecture → a 32-bit processor means each word is 32 bits, or 4 bytes at a time. A 64-bit processor 
Since 2^10 = 1024 which is around 10^3,  the term kilo was coined for 2^10. 1KB = 2^10 bytes, mega is 10^6 (around 2^20), and giga is 2^30 (around 10^9)
Binary Addition → If the sum of 2 numbers is greater than 1, we carry the 2’s digit over to the next column
Digital systems operate on a fixed number of digits, so if a result doesn’t fit in the available digits, we have overflow. The msb is discarded (most significant bit)

Signed Binary Numbers
: 2 schemes to represent signed (+/-) binary numbers → sign/magnitude and 2’s complement
: Sign/Magnitude Numbers
Uses the msb as the sign and the remaining N-1 bits as the magnitude. 
0 indicates positive and 1 indicates negative
Spans the range [-2^(N-1) → 2^(N-1) - 1]
When a 2’s complement number is extended to more bits, the sign bit must be copied into the most significant bit positions (sign extension)

1.5 Logic Gates
We now need to explore digital systems that perform operations on binary variables
Logic gates are digital circuits that take binary inputs and produce binary output 
: Gates are drawn with inputs on left and output on the right
: ‘A’ signifies a gate input, and ‘Y’ signifies a gate output
: A truth table:
A Y
0 1
1 0
**Truth table for a NOT gate
Types of gates:
: NOT gate
: Buffer → copies the input to the output
	: Although it acts basically as just a wire it has the ability to deliver large amount of current to a motor or send its output to multiple different gates (so basically its like a fort, it can multiply and strengthen)
	: AND gate (receives 2 signals)
	A B  Y
	0 0  0
	0 1  0
	1 0  0
	1 1  1
** Hypothetically, if we combine the 1001 with 1010 with AND, we get 1000, a completely different result
	→ true output if and only if both A and B are TRUE
	→ written as Y = AB, Y = A * B, or Y = A intersection B
	
	: OR gate
	→ produces a true output if A or B are true
	: XOR gate
	→ (pronounced ex-OR)
	→ is TRUE if A or B are TRUE, but not both TRUE
		: basically, it checks for differences, if the 2 inputs are different, then we get a TRUE, if both are same, we get a FALSE
any gate can be followed by a bubble to invert its operation (basically do the normal operation and invert the output)
Multiple-input gates
	: an N-input AND gate produces a TRUE when all N-inputs are TRUE
** HOW CAN these be used to make an Application? Theory: ABSTRACTION: We are at L6 of the hierarchy; so we start with 0’s and 1’s in digital circuits which are programmed to allocate the data into adders and memories, which are allocated via gates.

Ex. for 3 inputs

NOR3:
A B C Y
0 0 0  1
0 0 1 0
0 1 0 0
0 1 1 0 
etc.

"""
"""

1.6 Beneath the Digital Abstraction

Digital system uses discrete-valued variables
A designer must find a way to relate continuous values to a discrete value.
	: this is necessary for the case of a 1 meaning 1.5V and a 0 meaning 0V. What if there are 0.28 V? Or there are 0.75 V?

1.6.2 Logic Levels

- Mapping continuous variables (voltage) into discrete variables in binary is done by defining logic levels

- The first gate is the driver, and the second gate is the reciever
- They are in series.

- The driver produces a LOW (0) output in the range of 0 to VOH. The HIGH (1) is produced in the range VOL to VDD. 
- The reciever recieves a LOW (0) output in the range of 0 to VIL and from VIH to VDD.

1.6.3 Noise Margins

nm (low) = VIL - VOL
nm (high) = VOH = VIH

For Correct interpretation, Vol < VIL, and VOH > VIH

Even with some noise, the input of the reciever will still detect the correct logic level. The noise margin is the amount of noise that could be added to a worst-case output such that the signal can still be interpreted as a valid input. 

1.6.4 DC Transfer Characteristics

Let us observe the analog characteristics of a gate, which describe the output voltage as a function of the input voltage:

Ideal vs Real inverter
	: ideal inverter would have an abrupt switching threshold at VDD/2
	: a real inverter changes more gradually between the extremes, when the input voltage is 0, the output voltage is VDD. 

"""
"""

1.6.5 The Static Discipline

Static discipline requires that, given logically valid inputs, every circuit element will produce logically valid outputs
Digital designers sacrifice the freedom of arbitrary analog circuit elements in return for simplicity and robustness of digital circuits
- The choice of logic levels must have compatible logic levels
- gates are grouped into logic families such that all gates in a logic family obey the static discipline when used with other gates in the family
	: in other words, all gates in a family end up producing a logically valid output given a logically valid input
	: 4 dominant logic families from the 1970's:
		-> Transistor-Transistor Logic, Complementary Metal-Oxide-Semiconductor Logic, Low Voltage TTL Logic, Low Voltage CMOS Logic

Logic Family	VDD	VIL	VIH	VOL	VOH	

TTL		5	0.8	2.0	0.4	2.4
CMOS		5	1.35	3.15	0.33	3.84
LVTTL		3.3	0.8	2.0	0.4	2.4
LVCMOS		3.3	0.9	1.8	0.36	2.7

"""
"""

1.7 CMOS Transistors

- modern computers use transistors because they are cheap, small, reliable
- transistors are basically electrically controlled switches that turn ON or OFF when a voltage or current is applied to a control terminal 

- we can now fit 1 billion MOSFETs onto a 1 cm^2 chip of silicon
- MOSFETS are the building blocks of almost all digital systems

1.7.1 Semiconductors

MOS transistors are built from silicon
- Silicon is a group IV atom, having 4 electrons in its valence shell and forms bonds with four adjacent atoms, resulting in a crystalline lattice
- It becomes a better conductor when small amounts of impurities, dopant atoms, are carefully added
- These have an extra electron that aren't bonded covalently
	: for example, Arsenic (As) can be used as a dopant, which carries a net negative charge, making it an n-type dopant
	: with the lack of an electron, group III dopants such as boron (B), leaves a positively charged hole, which can be considered a positive particle
	-> this would be considered a p-type dopant

- Because the conductivity of silicon changes over many orders of magnitude depending on the concentration of dopants, silicon is a semiconductor

1.7.2 Diodes

- the junction between p-type and n-type silicon is called a diode
- the p-type region is the anode and the n-type region is the cathode
- when the voltage on the anode rises above the voltage on the cathode, the diode is forward biased, and current flows through the diode from the naode to the cathode
	: however, when the anode voltage is lower than the cathode voltage, the diode is reverse biased, and no current flows

1.7.3 Capacitors

A capacitor consists of 2 conductors separated by an insulator

- When a voltage V is applied to one of the conductors, the conductor accumulates charge Q and the other conductor accumulates charge -Q. 
- Capacitance is important because charging and discharging a conductor takes time and energy
	: more capactiance means a circuit is slower and requires more energy

1.7.4 nMOS and pMOS Transistors

- To make a MOSFET, a bare wafer of silicon is used. Dopants are then implanted into the silicon, the wafer is patterned. A thin layer of SiO2 is grown onto the silicon-dopant mixture. A thin layer of metal is then deposited. The wafer is cut into rectangles called chips or dice, that contain thousands to billinois of transistors. This "chip" is tested, then placed in a plastic or ceramic package with metal pins to connect it to a circuit board. 

We now have a sandwich of a metal-oxide-semiconnductor, or MOS(FET) and when used as a transistor, a MOSFET. 

- A MOSFET behaves as a voltage-controlled switch in which the gate voltage creates an E-field that turns ON or OFF a connection between the source and drain

- If voltage is applied at the gate, electrons in both n-type regions are attracted to the gate, making a negativley charged region between the n-type semiconductors. This allows for current to flow.
- For a p-type MOSFET's positive holes get filled up by the electrons that are pulled up by the E-field, creating no current.

1.7.5 CMOS NOT Gate

- See a diagram
- p1 is connected to Vdd and n1 is connected to ground. A feeds into both p1 and n1. If A is 1, then p1 turns off and output is 0. If A is 0, P1 turns on and output is 1.

1.7.6 Other CMOS Logic Gates

When transistors are in series, the network is ON only if both are ON, and when in parallel, the network is ON when either is ON.

- If both the pull-up and pull-down network are on, we get a short circuit, as VDD would be directly connected to ground.

- If both networks are off, then it is neither a 0 or 1, and the result floats, making an undefined anwer. 

- In a properly functioning network, either networks should be on or off, which can be guaranteed by using the rule of conduction complements
	: When nMOS are in series, pMOS must be in parallel. When nMOS are in parallel, pMOS must be in series

1.7.7 Transmission Gates

Putting the pull-down system in parallel with the pull-up system passes both 0 and 1 well (well = if on, then produces 1 for pull-up and 0 for pull-down. 

1.7.8 Psuedo-nMOS Logic

- An N-input CMOS NOR gate uses N nMOS transistors in parallel and N pMOS transistors in series
- Transistors are slower in series thann parallel, because there are more clock cycles everytime data runs into a new transistor
- pMOS transistors are slower than nMOS transistors, because holes move slower than electrons

- psuedo-nMOS logic replaces the 2 pMOS transistors with a weak pMOS transistor that is always on, called a weak pull-up. The pMOS transistor will weakly pull the output Y up to 1. However, ifeither nMOS transistor is ON, it overpowers the weak pull-up and pulls Y close enough to GND to make 0.
	: this is very useful for building fast NOR gates with multiple inputs.
	: the disadvantage is when the output is LOW, there is a constant short circuit which will draw a lot of power

"""
"""

1.8 Power Consumption

Digital systems draw dynamic and static power
	: dynamic power -> power used to charge capacitance as sgnals change between 0 and 1
	: static power: power used even when the system is idle and signals do not change

- Logic gates and wires have capacitance
E = C * V**2

P = dE/dt. 
Pd (dynamic) = 0.5 * C * V**2
Ps = IVdd
Where I is the leakage current flowing between Vdd and gnd.

"""
