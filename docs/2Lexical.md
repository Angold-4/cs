# 2. Lexical Analysis


#### User view
```c
if (i == j) 
    z = 0;
else 
    z = 1;
```

#### Compiler view
```
if (i == j)\n\t\tz = 0;\n\telse\n\t\tz = 1;
```

## 1. Formal Languages

### Seperate Syntax and Semantics
* Makes clear what is syntax, what is semantics.
* Example: **Roman numerals vs. Arabic numerals**
    * Roman numerals are painful to do addition and subtraction, etc.
    * The reason is that the algorithms were kind of complicated.
    * The notation causes this big difference (procedure)
    * Don't underestimate the importatance of notation.

### Syntax vs. Semantics
* We can use **Multiple syntax** to represent the **same semantics.**
* Which is the basis of **Optimization.**
* The fact that several programs that are actually functionally equivalent, that allow us to substitute one program that runs faster than another.
* **Never one to many!!!**
