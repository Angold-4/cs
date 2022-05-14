## An introduction to creating a C compiler - weicc

# 2. Calculator-level Language Creation

![ultra](Sources/ultra.jpg)

In the **[previous ariticle](https://angold4.org/cs/docs/weicc/1Thompson1984.html)** of this series. **I gave you some sort of "taste" of a compiler by giving a simple 30-line C program, which is a small compiler that can only generate code of add and substract operations.**

After you compile and test that code on your machine, back to the implementation, you may wonder the difference between mordern compiler and this small "compiler": they all meet the definition of a compiler.

So, what is the difference? In my opinion, like I mentioned in **[cs.1 Introduction](https://angold4.org/cs/docs/lectures/1Introduction.html)**:
> **To reduce the complexity of implementation, people divide the whole compiler into different *stages*.**

Theoretically, a single-pass, monolithic compiler structure would work, but it hard to implement, especially in **debugging** and **cooperating**, if you implement a compiler in this way (we did it in this 30-line code), the whole compiler is just a **Code Generator** (so-called the **Back End**). 

![stages](Sources/stages.png)

However, the mordern compiler, who recieves some unknown, unpredictable input stream, just like I said before, it is difficult to use a single **Code Generator** to emit code for such complex input sources.

**"Dividing compiler into multiple stages"** is a very brilliant idea, not only does it reduce the complexity of implementing a mordern compiler by making the differet stages independently, but it also make it way much easier for the student to understand a mordern compiler.

But at the same time, we should also notice the side-effects of this design choice: **It is easy to bring an illusion to the beginner that all compilers should contain these 4 or 5 different stages.** If they learn the compiler stage by stage, which means, only learn the parser after they fully understand the tokenizer, only touch code generator after they fully understand the front end, etc., I believe it is not the correct way:
1. **Since each part's output (immediate code) is used for the next part (in the other words, the earlier part "serves" the later part ), there is no "fully understand" before you touch the next part and knowing that what does it want.**

2. **In general, the compiler should never be developed from stage to stage, it always start with a full-stages, small piece of code, and after adding more features to each part gradually at the same time. Finially becomes the "complex mordern compiler".**

**In our example here, this "30-line c code" is nothing but a small code generator due to the simple and predictable input source. But if we want to add more features to this compiler, we should add more stages in order to help our code generator emit code.**

I think that is one of the correct way to understand a compiler, and what I am going to do in this Chapter is add a **Tokenizer** and a **Parser** to our compiler in order to support more complex operations like **division `/`** and **multiplicatin `*` **.

## 1. Tokenizer


## 2. Parser
