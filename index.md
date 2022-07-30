# cs

![mmmjpeg](docs/weicc/Sources/mmm.jpeg)

## Rob Pikes's 5 Rules of Programming
* **Rule 1**. You can't tell where a program is going to spend its time. Bottlenecks occur in surprising places, so don't try to second guess and put in a speed hack until you've proven that's where the bottleneck is.
* **Rule 2**. Measure. Don't tune for speed until you've measured, and even then don't unless one part of the code overwhelms the rest.
* **Rule 3**. Fancy algorithms are slow when n is small, and n is usually small. Fancy algorithms have big constants. Until you know that n is frequently going to be big, don't get fancy. (Even if n does get big, use Rule 2 first.)
* **Rule 4**. Fancy algorithms are buggier than simple ones, and they're much harder to implement. Use simple algorithms as well as simple data structures.
* **Rule 5**. Data dominates. If you've chosen the right data structures and organized things well, the algorithms will almost always be self-evident. Data structures, not algorithms, are central to programming.


## Lectures (Stanford CS-143)
* **1. [Introduction](docs/lectures/1Introduction.html)**
* **2. [Lexical Analysis](docs/lectures/2Lexical.html)**
* **3. [Parsing](docs/lectures/3Parse.html)**


## acc: A simple integer arithmetic calculator
* **[acc.c](acc/acc.c)**


## weicc: A small C compiler

* **[weicc repository on github](://github.com/Angold-4/weicc)**

1. **[Thompson-1984](docs/weicc/1Thompson1984.html)**
2. **[Calculator-level language creation](docs/weicc/2Calculator.html)**

## Parsing Techniques
* **[Parsing Techniques](./docs/parsingtech/ParsingTechniques.pdf)** by Dick Grune & Ceriel J.H. Jacobs

1. **[Parsing and Grammars](./docs/parsingtech/1Introduction.html)**
