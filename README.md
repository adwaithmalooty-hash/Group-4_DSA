# Expression Tree and Postfix Evaluation Using C

## 1. Project Overview

This project demonstrates the implementation of an Expression Tree using the C programming language. It uses a postfix expression to construct a binary expression tree, performs tree traversals, and evaluates the mathematical expression.

An expression tree is a binary tree in which internal nodes represent operators and leaf nodes represent operands. It is commonly used in compilers, calculators, and mathematical expression processing.

## 2. Problem Statement

Construct an expression tree for the following postfix expression:

```text
8 3 2 * + 6 2 / -
```

Perform the following operations:
1. Construct the expression tree.
2. Display inorder traversal.
3. Display preorder traversal.
4. Display postorder traversal.
5. Evaluate the expression.
6. Compare stack-based postfix evaluation with expression tree evaluation.

## 3. Objectives

- Understand postfix expressions.
- Learn how to construct a binary expression tree.
- Implement a stack using an array of pointers.
- Perform inorder, preorder, and postorder traversals.
- Evaluate a mathematical expression using recursion.
- Understand the time and space complexity of the solution.

## 4. Technologies Used

- Programming Language: C
- Data Structure: Binary Tree
- Supporting Data Structure: Stack
- Compiler: GCC or another standard C compiler
- Platform: Windows, Linux, or macOS

## 5. Postfix Expression

The given postfix expression is:

```text
8 3 2 * + 6 2 / -
```

A postfix expression places operators after their operands. Parentheses are not required to specify the order of operations.

## 6. Expression Tree

The expression tree for the given postfix expression is:

```text
             -
           /   \
          +     /
         / \   / \
        8   * 6   2
           / \
          3   2
```

### Explanation

- The root node is the subtraction operator (-).
- The left subtree represents 8 + (3 * 2).
- The right subtree represents 6 / 2.
- The multiplication operator (*) has 3 and 2 as its children.
- The division operator (/) has 6 and 2 as its children.

The complete expression is:

```text
(8 + (3 * 2)) - (6 / 2)
```

## 7. Algorithm

1. Start the program.
2. Read the postfix expression.
3. Scan the expression from left to right.
4. If the current character is an operand, create a node and push it onto the stack.
5. If the current character is an operator, create an operator node.
6. Pop the right operand from the stack and assign it as the right child.
7. Pop the left operand from the stack and assign it as the left child.
8. Push the operator node back onto the stack.
9. Continue until the entire expression is processed.
10. The remaining node on the stack becomes the root of the expression tree.
11. Perform inorder, preorder, and postorder traversals.
12. Evaluate the expression tree recursively.
13. Display the traversals and final result.
14. Stop the program.

## 8. Step-by-Step Evaluation

The postfix expression is:

```text
8 3 2 * + 6 2 / -
```

### Step 1: Multiplication

```text
3 * 2 = 6
```

The expression becomes:

```text
8 + 6 - 6 / 2
```

### Step 2: Addition

```text
8 + 6 = 14
```

### Step 3: Division

```text
6 / 2 = 3
```

### Step 4: Subtraction

```text
14 - 3 = 11
```

### Final Result

```text
11
```

## 9. Tree Traversals

Tree traversal is the process of visiting all nodes of a tree in a particular order.

### 9.1 Inorder Traversal

Inorder traversal follows the order: Left, Root, Right.

Output:

```text
8 + 3 * 2 - 6 / 2
```

### 9.2 Preorder Traversal

Preorder traversal follows the order: Root, Left, Right.

Output:

```text
- + 8 * 3 2 / 6 2
```

### 9.3 Postorder Traversal

Postorder traversal follows the order: Left, Right, Root.

Output:

```text
8 3 2 * + 6 2 / -
```

The postorder traversal matches the original postfix expression.

## 10. Stack-Based Postfix Evaluation

A stack is used to evaluate a postfix expression.

| Token | Operation | Stack |
|---|---|---|
| 8 | Push 8 | 8 |
| 3 | Push 3 | 8, 3 |
| 2 | Push 2 | 8, 3, 2 |
| * | Calculate 3 * 2 = 6 | 8, 6 |
| + | Calculate 8 + 6 = 14 | 14 |
| 6 | Push 6 | 14, 6 |
| 2 | Push 2 | 14, 6, 2 |
| / | Calculate 6 / 2 = 3 | 14, 3 |
| - | Calculate 14 - 3 = 11 | 11 |

The final stack contains the result 11.

## 11. Expression Tree Evaluation

The expression tree is evaluated recursively.

1. Evaluate the left subtree: 8 + (3 * 2) = 14.
2. Evaluate the right subtree: 6 / 2 = 3.
3. Apply the root operator: 14 - 3 = 11.

Final result: **11**

## 12. Expected Output

When the C program is compiled and executed, the expected output is:

```text
Inorder   : 8 + 3 * 2 - 6 / 2
Preorder  : - + 8 * 3 2 / 6 2
Postorder : 8 3 2 * + 6 2 -
Value     : 11
```

## 13. How to Compile and Run

### Step 1: Install a C Compiler

Install GCC or another C compiler if one is not already available.

### Step 2: Compile the Program

Open a terminal in the project directory and run:

```bash
gcc expression_tree.c -o expression_tree
```

### Step 3: Run the Program

On Linux or macOS:

```bash
./expression_tree
```

On Windows:

```bash
expression_tree.exe
```

## 14. Comparison: Stack-Based Postfix Evaluation vs Expression Tree

| Feature | Stack-Based Postfix Evaluation | Expression Tree |
|---|---|---|
| Data structure | Stack | Binary tree and stack for construction |
| Evaluation | Directly evaluates postfix tokens | Evaluates recursively through the tree |
| Time complexity | O(n) | O(n) |
| Space complexity | O(n) in the worst case | O(n) for the tree and stack |
| Structure visibility | Does not directly show tree structure | Shows operator-operand relationships |
| Traversals | Not applicable to the expression itself | Supports inorder, preorder, and postorder |
| Main use | Quick expression evaluation | Expression representation, analysis, and evaluation |

## 15. Advantages of Expression Trees

1. They represent mathematical expressions clearly.
2. They show the relationships between operators and operands.
3. They support different traversal methods.
4. They can be evaluated recursively.
5. They are useful in compiler design and expression processing.
6. They make the structure and order of operations easier to understand.

## 16. Time and Space Complexity

Let n be the number of tokens in the expression.

### Time Complexity

- Constructing the expression tree: O(n)
- Inorder traversal: O(n)
- Preorder traversal: O(n)
- Postorder traversal: O(n)
- Evaluating the expression tree: O(n)

Each operation visits or processes each node a constant number of times.

### Space Complexity

- Expression tree storage: O(n)
- Stack used during construction: O(n) in the worst case
- Recursive traversal and evaluation: O(h), where h is the height of the tree

The overall auxiliary space requirement is O(n).

## 17. Applications

Expression trees are used in:

- Mathematical expression evaluation
- Compiler design
- Arithmetic calculators
- Syntax analysis
- Expression conversion
- Symbolic computation
- Programming language processing

## 18. Project Files

The repository contains the following files:

```text
Q4_Expression_Tree_Project/
├── expression_tree.c
├── README.md
├── output.txt
└── question4_answer.txt
```

### File Descriptions

- **expression_tree.c:** Contains the C implementation for constructing, traversing, and evaluating the expression tree.
- **README.md:** Provides the project overview, algorithm, explanation, output, and complexity analysis.
- **output.txt:** Contains the expected output.
- **question4_answer.txt:** Contains the written answer to Question 4.

## 19. Conclusion

This project demonstrates how to construct an expression tree from a postfix expression using a stack. It also demonstrates inorder, preorder, and postorder traversal and recursive expression evaluation.

For the postfix expression:

```text
8 3 2 * + 6 2 / -
```

the final result is:

```text
11
```

Both stack-based postfix evaluation and expression tree evaluation can solve the expression efficiently. However, an expression tree also provides a visual representation of the operators, operands, and their relationships.

---

**Project:** Expression Tree and Postfix Evaluation  
**Language:** C  
**Topic:** Data Structures  
**Result:** 11

