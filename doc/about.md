## Data Types

## Tokens

Tokens are basic information units obtained from single characters or a collection of related characters. For instance, '+' is treated as a token of type 'TK_PLUS' and '342' is treated as a token of type 'TK_INT'.

## Nodes

Nodes are the smallest unit of an abstract syntax tree (AST), derived from the structured analysis of tokens (done with right recursion). They represent groupings of operations. For instance, a node can be '(3)->(+)<-(2)', where (+) is the root node and (3) and (2) are the left and right nodes respectively. Once an AST is gathered, it can be used to transform the initial input into a determined language (assembly or some intermediate representaton), as well as a final result of mathematical operations.

# source/bootstrap Folders and Files

## lex/

This folder contains functions related to tokenization (see Tokens above).

## node/

Implementation of the NODE data type, as well as some utility functions related to nodes.

## parse/

This folder contains functions related to parsing (see Nodes above).

## token/

Implementation of the TOKEN and TK_LIST data types, as well as some utility functions related to tokens.

## typedef.h

Contains type definitions that resemble the target language more closely. For instance 'int' becomes 'i32' and 'unsigned long int' becomes 'u64' (on 64-bit platforms).
