The Analysis Framework
1. Time Efficiency (or) Time Complexity
    - how fast does the algorithm run 
2. Space Efficiency 
    - the ammount of memory units required by the algorithm in addition to the space needed for the input and output 

Measuring Input Size 
    Array -> n 
    Matrix -> (n x m) dimensions -> N total # of elements 
    Spell check algorithm -> # of characters
                          -> # of words

Units for Measuring Time
-Basic Operation
    -> the most important operation of the algorithm
    -> typically will be found in the inner most loop
    -> contributes the most to the total running time 
        CBaseOp -> execution time of the algorithms basic operation (on a particular computer)
        C(n) -> number of times this operation needs to be executed for an algorithm
    Time Efficency, [T(n) = CBaseOp * C(n)]

Input size -> 2n
    logbase2(n) -> logbase2(2n) = logbase2(2) + logbase2(n)
                                = 1 + logbase2(n) -> increases by 1
    n -> 2n -> doubled
    nlogn -> 2nlog2n = 2n(logbase2(2) + logbase2(n))
                     = 2n(1 + logbase2(n)) -> more than 2-fold increase
    n^2 -> (2n)^2 = 4n^2 -> 4-fold increase
    n^3 -> (2n)^3 = 8n^3 -> 8-fold increase
    2^n & n! -> exponential growth function 

-> a computer that solves 10^12 operations per second, to execute 2^100 operations -> 4 x 10^10 years
        100! -> takes much longer 

ALGORITHM Sequential Search (A[0...n-1],k)
// Searches for the search key, k in the arrray A by sequential search
// Input : Array A[0...n-1] and a search key 'k'
    i <- 0
    while i < n and A[i] != k do
        i <- i + 1
    if i < n return i 
    else return -1

    Input size -> n
    Basic operation (will be within the loop) -> A[i] != k (key comparison)
        * why?
            -options:
                * i <- i + 1
                * i < n
                * A[i] != k
            -i <- i + 1 wont happen every time bc the checks may return false and not enter loop
                * i < n
                * A[i] != k (takes a longer time to execute so its the basic operation!!!)
    Worst-case -> Cbaseworst(n) = n 
    Best-case -> Cbasebest(n) = 1
    Average-case efficiency
        * for a typical or random input,
            p -> probability of a successful search
            1-p -> probability of an unsuccessful search
            -> ...so for a successful search, the probability of the first match occuring at position 'i' is,
                p/n for every i
            -> Cbaseavg(n) = [1 * p/n + 2 * p/n + 3 * p/n + ... + i * p/n + ...] + n(1-p)
                        = p/n [1+2+3+...+n] + n(1-p)
                        = p/n * n(n+1)/2 + n(1-p)
                        = p(n+1)/2 + n(1-p)
        * for a successful search, p = 1
            -> Cbaseavg(n) = n+1/2
        * for an unsuccessful search, p = 0
            -> Cbaseavg(n) = n 

ASYMPTOTIC NOTATIONS & BASIC EFFICIENCY CLASSES
-Big-Oh notation (or) O-notation :-
    * A function t(n) is said to be in O(g(n)), if t(n) is bounded ABOVE by some constant multiple of g(n) for all large n, i.e.;
        there exists some positive constant 'c' and some non-negative integer nbase0 such that 
        t(n) <= cg(n) for all n >= nbase0
        -> t(n) E O(g(n))
    * Ex(1)
        t(n) = 100n + 5
        g(n) = n^2

        Option 1:
            100n + 5 <= 100n + n    for all n >= 5
                        
            101n <= 101n^2
            t(n) <= cg(n)           where c = 101, n >= 5
            
            -> t(n) E O(g(n))       where c = 101, nbase0 = 5
            Hence, proved by definition.

        Option 2:
            100n + 5 
            100n + 5n               for all n >= 1
                105n
            105n <= 105n^2
            t(n) <= cg(n)

            -> t(n) E O(g(n))       where c = 105, nbase0 = 1
            Hence, proved by definition

    * Flexibility to choose 'c' and 'nbase0'
        Order of growth of <= order of growth of
             t(n)                   g(n)
        -> t(n) E O(g(n))

-Big-Omega or Omega-notation :-
    * A function t(n) is said to be in omega(g(n)), if t(n) is bounded BELOW by some constant multiple of g(n) for all large n, i.e.;
        there exists some positvie constant 'c' and some non-negative integer 'nbase0' such that 
        t(n) >= cg(n) for all n >= nbase0
        -> t(n) E omega(g(n))
    * Ex(1)
        t(n) = n^3
        g(n) = n^2

        n^3 >= n^2              for all n >= 0

        -> t(n) E omega(g(n))   where c = 1, nbase0 = 0
           [n^3 E omega(n^2)]
           Hence, proved by definition

