/**
Algorithm: A sequence of unambiguous instructions for solving a problem
    Properties:
    1. Definite: Each step must be unambiguously specified
    2. Effective: Each step is sufficently simple and basic
    3. Finite: Terminates after a finite number of steps
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
        
Method #3 Middle School Procedure GCD(m,n)
    Step 1: Find the prime factors of m 
    Step 2: Find the prime factors of n 
    Step 3: Identify all common factors found in Steps #1 and #2
        If 'p' is a common factor, which occurs Pm in m and Pn in n respectively, then
            it should be repeated min(Pm,Pn) times
    Step 4: Compute the product of all common factors and return it as the GCD

    (ex) GCD(60,24)
        60 = 2 x 2 x 3 x 5
        24 = 2 x 3 x 2 x 2

        Common factors: 2 x 2 x 3 = 12

Design an algorithm to generate a list of consecutive prime numbers less than or equal to 'n'
    let n = 25
        -> 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
    
    Iteration-1 : Eliminates all multiples of 2
        2 3 5 7 9 11 13 15 17 19 21 23 25

    Iteration-2 : Eliminates all multiples of 3
        2 3 5 7 11 13 17 19 23 25
    
    Iteration-3 : Eliminates all multiples of 5
        2 3 5 7 11 13 17 19 23
    
    Iteration-4 : Eliminates all multiples of 7
        Nothing to eliminate so we STOP here!!
        Final list: [2 3 5 7 11 13 17 19 23]

    Pattern we noticed:
        p * p is the first value we deleted per iteration (2x2, 3x3, 5x5)
            p * p <= n 
            p^2 <= n 
            p <= sqrt(n)
^
|
Algorithm Sieve(n) [Sieve of Eratosthenes]
    // Input : A positive number, n > 1
    // Output : Array L of all prime numbers less than or equal to n

    for p <- 2 to n do A[p] = p
    for p <- 2 to sqrt(n) do 
        if A[p] != 0
            j <- p * p 
            while j <= n do
                A[j] <- 0
                    j <- j + p 
    i <- 0
    for p <- 2 to n do 
        if A[p] != 0
            L[i] <- A[p]
                i <- i + 1
    return L
