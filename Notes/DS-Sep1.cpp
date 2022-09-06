Using limits to compare order of growth :-
    * Definition: Lim            t(n) / g(n) = Lim           t^1(n) / g^1(n)      -> LHOPITALS RULE
                  n->infinity                  n-> infinity
    
    * 3 principal cases
        #1 = 0
            t(n) has a smaller order of growth than g(n)
        #2 = c // some constant
            t(n) has the same order of growth as g(n)
        #3 = infinity 
            t(n) has a larger order of growth than g(n)

    * Ex(1)
        t(n) = 1/2n(n-1)
        g(n) = n^2

        // using lhopitals rule
        Lim             t(n) / g(n) = Lim               1/2n(n-1) / n^2
        n -> infinity                 n -> infinity
                                      Lim               1/2(n-1) / n
                                      n -> infinity
                                      1/2 Lim           (n-1 / n)
                                      n -> infinity
                                      1/2 Lim           (1 - 1/n)
                                      n -> infinity
                                    = 1/2
        1/2n(n-1) E theta(n^2)
        Hence proved by using limits

    * Ex(2)
        t(n) = logbase2(n)
        g(n) = sqrt(n)

        Lim             t(n) / g(n) = Lim               logbase2(n) / sqrt(n)
        n -> infinity                 n -> infinity
                                      Lim               (lobbase2(e) * logbaseE(n)) / sqrt(n) // formula used: [logbaseA(n) = logbaseA(b)logbaseB(n)]
                                      n -> infinity
                                      logbase2(e) Lim   ln(n) / sqrt(n)
                                                  n -> infinity
                                      // applying lhopitals rule
                                      logbase2(e) Lim           (ln(n))^1 / (sqrt(n))^1
                                                  n -> infinity
                                      logbase2(e) Lim           1/n / 1/2sqrt(n)
                                                  n -> infinity
                                      logbase2(e) Lim           2 / sqrt(n)
                                                  n -> infinity
                                      2logbase2(e) Lim          1 / sqrt(n)
                                                  n -> infinity
                                      = 0
        logbase2(n) E O(sqrt(n))
        Hence proved by using limits

    Step #1 simplify fraction
    Step #2 lhopital rule (first order derivative)
    Step #3 apply limit (depending on answer, choose class)

    * Ex(3)
        t(n) = n!
        g(n) = 2^n

        Lim             t(n) / g(n) = Lim               n! / 2^n
        n -> infinity                 n -> infinity
                                      Lim               (sqrt(2PIn) * (n/e)^n) / 2^n    // using stirlings formula [n! = sqrt(2PIn) * (n/e)^n]
                                      n -> infinity
                                      Lim               sqrt(2PIn) * (n/2e)^n
                                      n -> infinity
                                      = infinity
        n! E omega(2^n)
        Hence proved using limits

SIDE NOTE: Need to know before next class
    -log rules
    -manipulate base and exponent
    -first order derivatives
    -simplifying fractions

Properties of orders of growth
    #1 If f(n) E O(g(n)) then g(n) E omega(f(n))

    #2 If f(n) E O(g(n)) and g(n) E O(h(n)) then 
            f(n) E O(h(n))

    #3 If f1(n) E O(g1(n)) and f2(n) E O(g2(n)) then
            f1(n) + f2(n) E O(max {g1(n), g2(n)})

Important formulas
// E equals summation
#1  u 
    E   1 = u - l + 1       where l <= u 
   i=l

#2  n        n
    E   i =  E  i
   i=0      i=l

#3  u               U
    E   cabasei = c E   abasei
   i=l             i=l

#4  u                        u            u
    E   (abasei +- bbasei) = E  abasei +- E bbasei
   i=l                      i=l          i=l

MATHEMATICAL ANALYSIS OF NON-RECURSIVE ALGORITHMS
    ALGORITHM MaxElement (A[0...n-1])
        max <- A[0]
        for i <- 1 to n-1 do 
            if A[i] > max 
                max <- A[i]
        return max 
    
    Input size -> n
    Basic operation -> key comparison (if A[i] > max)
    // E equals summation or includes
    n-1
     E  1 = n-1 - 1 + 1 // using the first formula under important formulas
    i=1
          = n - 1 E theta(n)