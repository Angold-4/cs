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

The **"linear representation"** that shown in the definition may be a sentence, a computer program, a knitting pattern, a sequence of geological strata, or even a piece of music. and they do have something in common: 

1. Any linear representation (sequence) has some **rule** with it, which tells the parser whether it is an valid sequence, and tells us the meaning of the representation. We call that rule **grammar**.

2. Any linear representation (sequence) in which the **preceding elements in some way restrict the next element**.
    * For example: Consider a simple calculator "**`1 + 2 =`**": if the preciciding element in that expression is a number, say `3`, **it will restrict its next element so that it can only be a symbol (e,g. `+`)**.
    * If there is no restriction, the sequence still has a grammar, but this grammar is trivial, uninformative and hard to understand.

### ii. The Purpose of Parsing

For each grammar, there are generally an infinite number of linear representations (aka "sentence") that can be structured with it. **The finite-size grammar can supply structure to an infinite number of sentences.** And that is the purpose of a grammar: **To Summarize succinctly the structure of an infinite number of objects of a certain class."**

In general, there are two reasons to perform this structuring process called parsing:

1. **After parsing a given sentence, we can show that whether this sentence can be recongnized according to a grammar.** And for the error-repairing parsers, they can suggest possible word classes for missing or unknown words on clay tablets.

2. **Grammars usually have semantics attached to them** (Specific sementics is attached to specific rules); **The obtained structure (e.g. parse tree) of parsing can help us to process the sentence fucther. (understand its semantics)**
    * The obtained structure often shows which rules were involved in the production of a string and how.
    * Reconginition is not enough, we need parsing to get the full benefit of the syntactic approach.

## 2. Grammars as a Generating Device

Everyone who has studied a foreign language knows that a grammar is a book of rules and examples which describes and teaches the language. The computer scientist takes a very abstracted view of it, which not only can grammar describe a language, **but also it should show the recipe of that language (the recipe should imply how a sentence can be constructed).**

Quite unlike human, the computer needs a **clear, well-understood and unambiguous grammar** in order to process its language. In the human's world, the linguist holds his view of language because it gives him a formal tight grip on a seemingly chaotic and perhaps infinitely complex object: **natual language**, and understand its meaning through the human's heart.


### i. Describing a language through a finite recipe.

**A good way to build a set of objects is to start with a small object and to give rules how to add to it and construct new objects from it.** For example, "Two is an even number and the sum of two even numbers is again an even number" effectively generates the set of all even numbers. 


## 3. The Chomsky Hierarchy of Grammars

![30grammar](Sources/30grammar.png)




