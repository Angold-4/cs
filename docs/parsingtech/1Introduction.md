### Parsing Techniques Notes by Angold Wang

# 1. Parsing and Grammars 

Include Chapter 1 & 2 of the book: **[Parsing Techniques](ParsingTechniques.pdf)**.

**Parsing (syntactic analysis) is probably one of the best understood branches of computer science.** And of course parsers are being used extensively in a number of disciplines:

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

Suppose we want to generate the set of all enumerations of names, of the type "Tom, Dick and Harry", in which all names but the last two are separated by commas.

For example, in this case, we will not accept "Tom, Dick, Harry" nor "Tom and Dick and Harry". And Only "Tom, Dick and Harry" would be right. **A simple-minded recipe would be:**

#### Recipe #1
0. Tom is a name, Dick is a name, Harry is a name;
1. a name is a sentence;
2. a sentence followed by a comma and a name is again a sentence; 
3. before finishing, if the sentence ends in ", name", replace it by "and name".

**Although this seems will work for a cooperative reader, there are several things wrong with it:**

#### Problems of Recipe #1
1. **In Clause 3, the sentence does not really end in ", name", it actually end in ", Dick" or such.**
    * The "name" is just a symbol that stands for the real name. it will be replaced by a real name as given in rule 1.
    * **To Solve it, we define that there are two kinds of symbols involved here: terminals and non-terminals**.
    * **terminals** (short for "terminal symbols") are symbols that will occur in finished sentences. (e.g, "tom")
    * **non-terminals** (a singularly unin-spired term) which are the intermediate symbols that cannot occured in a finished sentence.

2. **As I mentioned above, the computer needs a clear and generative grammar in order to process its language.** 
    * In Clause 1, the "$X$ is a $Y$" should be replaced by "$Y$ may be replaced by $X$".


**This gives us the Recipe #2:** 

(To distinguish them, we write terminals in small letters and start non-terminals with a bond capital.)

#### Recipe #2
0. **Name** may be replaced by "tom" | **Name** may be replaced by "dick" | **Name** may be replaced by "harry"
1. **Sentence** may be replaced by **Name**
2. **Sentence** may be replaced by **Sentence, Name**
3. **", Name"** at the end of a **Sentence** must be replaced by **"and Name"** before **Name** is replaced by any of its replacements
4. a sentence is finished only when it no longer contains non-terminals
5. we start our replacement procedure with **Sentence**

Clause 1 through 4 describe replacements, Clause 5 is not specific to this grammar. It is valid generally and is one of the rules of the game. Clause 6 tells us where to start generating.

#### Problem of Recipe #2

The Only problem of recipe #2 is also in Clause 4: most rules have "may be replaced", but this one has "must be replaced". And since we want a more generic and elegant grammar, we only want to use **may be replaced** in all of our rules.

This can be solved by adding an **end-marker** after it. And if we make the **end-marker** a **non-terminal** which cannot be used anywhere except in the required replacement from ", Name" to "and Name", we automatically **enforce the restriction that no sentence is finished unless the replacement test has taken place.**

Then for brevity we write -> instead of "may be replaced by" and here comes the final recipe #3:

#### Recipe #3
0. **Name** -> tom | **Name** -> dick | **Name** -> harry
1. **Sentence** -> **Name** | **Sentence** -> **List** End
2. **List** -> Name | **List** -> **List, Name**
3. **, Name End** -> and **Name**
4. the start symbol is **Sentence**

As we can see, **we have succeeded in implementing the notion "must replace" in a system that only uses "may replace"; looking more closely, we see that we have split "must replace" into "may replace" and "must not be a non-terminal".**

### ii. Formal Grammars

## 3. The Chomsky Hierarchy of Grammars

![30grammar](Sources/30grammar.png)



