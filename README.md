# Evaluating Postfix Operations
This lab concerns the coding of a program that evaluates
postfix expressions using a stack.

### Examples

Postfix Expression | Infix Expression | Result
-------------------|------------------|-------
`2 5 +`            | `2 + 5`          | `7`
`4 5 * 2 +`        | `4 * 5 + 2`      | `22`
`5 1 + 3 *`        | `(5 + 1) * 3`    | `18`
`1 4 + 10 4 - *`   | `(1  + 4) * (10 - 4)` | `30`
`3 2 ^ 5 -`        | `3 ^ 2 - 5`      | `4`

## Sample Output

This is a sample output in case you do all the extra credit:
```
$ make
g++ -c main.cpp -std=c++14 -Wall
g++ -c evaluator.cpp -std=c++14 -Wall
g++ -c token.cpp -std=c++14 -Wall
g++ main.o evaluator.o token.o -o postfix -std=c++11 -Wall
$ ./postfix
Normal Tests:
= = = = = = = = = = = = = = = = = = = = = = = = = = = = =
                       2 14 + 1 5 + * =    96	9.09
                            2 5 ^ 5 + = 37.00	18.18
 * * * * There was an error  * * * * 	4 + 5	27.27
                   2 3 ^ 3 * 21 3 / + = 31.00	36.36
                               15 2 / =  7.50	45.45
                     100 90 - 5 3 - / =  5.00	54.55
           10 5 - 2 * 4 3 ^ 2 3 / / + = 106.00	63.64
 * * * * There was an error  * * * * 	10 5+	72.73
 * * * * There was an error  * * * * 	some	81.82
          2 2 + 4 + 5 * 30 - 5 * 25 / =  2.00	90.91
                       4 5 10 3 - * + = 39.00	100.00
= = = = = = = = = = = = = = = = = = = = = = = = = = = = =
                              2.5 2 * =  5.00	33.33
             2.7172 3.0 ^ 3.1415954 / =  6.39	66.67
                1.2 5 * 0.75 0.75 + / =  4.00	100.00
= = = = = = = = = = = = = = = = = = = = = = = = = = = = =
```
