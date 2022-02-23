# 3. Parsing

## 1. Context-free Grammars

### i. The limitation of Regular Languages
* **The weakest formal languages widely used**
* **Finite automaton cannot remember # of times it has visited a particular state.**
* **There are a lot of languages that are non-regular** (Using pumping lemma)
    * i.e. Strings of balanced parentheses are not regular
    ![limitation](Sources/limitation.png)

### ii. Context-free Grammars
#### Why do we need CFG?
**There are a lot of things that Lexical Analysis cannot do, through there are also some complicated things that they can do.**

Not all strings of tokens are programs, the parser must distinguish between valid and invalid strings of tokens.

| Phase | Input | Output |
| ----- | ----- | ------ |
| Lexer | String of characters | string of tokens |
| Parser | String of tokens | Parse tree |

