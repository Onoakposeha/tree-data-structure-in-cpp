# Context-Free Grammar Validator for Tree-Defining Expressions

## Project Description

When you take a course on **Data Structures** and **Formal Language** in the same semester 😂. This project focuses on validating expressions that define a tree using a context-free grammar, and automatically contructing this tree in the computer memory. 
It also outputs the inorder, postorder and preorder traversals of the tree.

Nodes are denoted by single characters and parentheses, `(` and `)`, are used to mark the beginning and ending of subtrees, respectively.

## Informal Description of the Grammar
Suppose we have the following tree
````
A
├── B
│   ├── D
│   └── E
├── C
│   ├── F
│   │   ├── K
│   │   └── L
│   └── G
````

The corresponding expression will be `A(B(DE)C(F(KL)G))` 

### Formal Description of the Grammar (G):

- **G** = (V<sub>N</sub>, V<sub>T</sub>, S, P)
- **VN (Non-terminal symbols):** { S, A, B, C }
- **VT (Terminal symbols):** { x, (, ) }
- **S:** Start symbol
- **P (Production Rules):**
    ```
    S → x | x(xA)
    A → λ | xA | (B)C
    C → λ | x | xA
    B → x | xA
    ```

In this context, `x` is any single character that is not `(` or `)` and represents a node.

### Validation Conditions

The set of valid expressions `L(G)` includes expressions `E` that meet the following conditions:
1. **Symbol Check:** Every character in `E` must be `x`, `(`, or `)`.
2. **Starting Node:** The first character of `E` must be `x`.
3. **Balanced Parentheses:** The number of open parentheses `(` must equal the number of closed parentheses `)`.
4. **Missing Parent:** The sequences `)(` and `((` must not appear in `E`.
5. **Empty Subtree:** The sequence `()` must not appear in `E`.


## Features
- **Validation Logic:** Uses context-free grammar to validate tree-defining expressions.
- **Error Handling:** Ensures expressions have balanced parentheses and follow specified sequence rules.
- **Algorithm Explanation:** Detailed descriptions of the grammar and validation steps.
