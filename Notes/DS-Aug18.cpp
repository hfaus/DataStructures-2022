/**
Algorithm: A sequence of unambiguous instructions for solving a problem
    Properties:
    1. Definite: Each step must be unambiguously specified
    2. Effective: Each step is sufficently simple and basic
    3. Finite: Terminates after a finit number of steps
    4. Input: Valid inputs are clearly specified 
    5. Output: Can produce the correct output for a given valid input

Theoretical importance of algorithms
    It is the core of Computer Science
Practical importance of algorithms
    Searching, sorting, GPS, air travel routes, page ranking, etc.
**/

//Problem: Find the GCD of 'm' and 'n'
Method #1 Algorithm euclid GCD(m,n)
    while n != 0 do
        temp <- m mod n
        m <- n 
        n <- temp 
    return m

    (ex) m = 60
        n = 24

        temp -> 60 mod 24 = 12
        m -> 24
        n -> 12

        temp -> 24 mod 12 = 0
        m -> 12
        n -> 0
        STOP

        GCD of 60 and 24 is 12

Method #2 Censecutive integer checking algorithm GCD(m,n)
    Step 1: Assign min(m,n) to 't'
    Step 2: Divide m by t
        If the remainder is 0, then go to step 3
        Else if the reaminder is non-zero, then go to step 4
    Step 3: Divide n by t
        If the reaminder is 0, then return t as the GCD of m and n 
        Else fi the remainder is non-zero, then go to step 4
    Step 4: Decrease the value of t by 1 then go to step 2

    (ex) GCD(60,24)
        t = 24
        60 mod 24 = 12

        t = 23
        60 mod 23 != 0

        t = 22
        t = 21
        t = 20
        60 mod 20 = 0 
        24 mod 20 = 4 != 0
        ...
        t = 12

        Keeps going until 60 mod t = 0! A lot more iterations and harder to follow