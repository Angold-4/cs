### Parsing Techniques Notes by Angold Wang

# 1. Parsing and Grammars 

Include Chapter 1 & 2 of the book: **[Parsing Techniques](ParsingTechniques.pdf)**.

**Parsing (syntactic analysis) is one of the best understood branches of computer science.** And of course parsers are being used extensively in a number of disciplines:

### In Computer Science
* **Compiler Construction**
* **Database Interfaces**
* **Artificial Intelligence**
* ...

### In Linguistics
* **Text and Textual Analysis**
* **Natual language Translation and Recongnition**
* **Corpora Analysis**
* ...

In this series: **[Parsing Techniques Notes](https://angold4.org/cs/)**, I'm trying to illustrate the basic concepts, and techniques of **Parsing**, which are the notes of the book: **[Parsing Techniques](ParsingTechniques.pdf)** by **Dick Grune** and **Ceriel Jacobs**.

## 1. An Overview of Parsing
**"Parsing is the process of structuring a linear representation in accordance with a given grammar"**.

If you do not know what parsing is, here is the definition. But you may still confuse with that after reading it. Since this definition has been kept abstract on purpose, to allow as wide an interpretation as possible.

### i. The Target of Parsing

The **"linear representation"** that shown in the definition may be a sentence, a computer program, a knitting pattern, a sequence of geological strata, or even a piece of music. But they do have something in common: 

1. Any linear representation (sequence) has some **rule** with it, which tells the parser whether it is an valid sequence, and tells us the meaning of the representation. We call that rule **grammar**.

2. Any linear representation (sequence) in which the **preceding elements in some way restrict the next element**.
    * For example: Consider a simple calculator "**`1 + 2 =`**": if the preciciding element in that expression is a number, say `3`, **it will restrict its next element so that it can only be a symbol (e,g. `+`)**.
    * If there is no restriction, the sequence still has a grammar, but this grammar is trivial, uninformative and hard to understand.

### ii. The Purpose of Parsing

### iii. How to Parsing


## 2. Grammars as a Generating Device

## 3. The Chomsky Hierarchy of Grammars
