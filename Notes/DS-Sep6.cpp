Ways to solve:
#1 By definition
#2 By limits
    - Simplify
    - First order deriv of numerator or denominator (lhopitals)
        - Get an answer:
            * 0 - big oh
            * constant - big theta 
            * infinity - big omega

ALGORITHM UniqueElements (A[0...n-1])
    // finding unique elements within an array
    for i <- 0 to n-2
        for j <- i+1 to n-1 do // j doesn't start at 0 bc it would compare to itself
            if A[i] = A[j] return false
    return true 

    input size -> n (size of the array)
    basic operation -> key comparison (if A[i] = A[j])

    // E is summation
   n-2 n-1               
    E   E   1
   i=0 j=i+1

// #1  u 
//     E   1 = u - l + 1       where l <= u 
//    i=l

   n-2
    E   n -1 - (i + 1) + 1
   i=0

   n-2
    E   n - 1 - i - 1 + 1
   i=0 

   n-2
    E   n - 1 + i
   i=0  

   n-2         n-2
    E   n - 1 - E   i
   i=0         i=0 

        n-2    n-2
   (n-1) E  1 - E   i   
        i=0    i=0

// #1  u 
//     E   1 = u - l + 1       where l <= u 
//    i=l

                    n-2
    (n-1)(n-2-0+1) - E  i
                    i=0
    
    (n-1)^2 - [(n-2)(n-2+1) / 2]

// sum of first n natural numbers = n(n+1) / 2

    (n-1)^2 - (n-2)(n-1)/2

    (n-1) [2n-2-n+2 / 2]

    n(n-1) / 2

    1/2 n^2

// E is not summation

    E theta(n^2)

ALGORITHM MatrixMultiplication (A[0...n-1,0...n-1]
                                B[0...n-1,0...n-1])
    for i <- 0 to n-1 do 
        for j <- 0 to n-1 do 
            C[i,j] <- 0.0
            for k = 0 to n-1 do 
                C[i,j] <- C[i,j] + A[i,k] * B[k,j]
    return C 

    input size <- n (size of the array)
    base operation <-
        * C[i,j] <- C[i,j] + A[i,k] * B[k,j]
            operations: <- , + , *
                since + and * are arithmatic and are done the same amount, either can be chosen for base operation

   n-1 n-1 n-1
    E   E   E   1
   i=0 j=0 k=0  

// #1  u 
//     E   1 = u - l + 1       where l <= u 
//    i=l

   n-1 n-1
    E   E   n-1-0+1
   i=0 j=0

   n-1 n-1
    E   E   n
   i=0 j=0

   n-1   n-1
    E   n E 1 
   i=0   j=0

   n-1 
    E   n[n-1...(too slow on my part)] 
   i=0

   n-1 
    E   n^2
   i=0

      n-1
   n^2 E    1
      i=0

    n^2 [n-1-0+1]

    n^3

    M(n) = n^3

    doesn't equal of addition, A(n) = n^3

        T(n) = Cbasem M(n) + Cbasea A(n)
             = (Cbasem + Cbasea) M(n)       // M(n) = A(n)

        T(n) E O(n^3)

MATHEMATICAL ANALYSIS OF RECURSIVE ALGORITHMS
    Problem: Compute the facotrial of a number (non-negative integer value)
    ALGORITHM Factorial F(n)
        if n = 0 return 1       // 0 factorial is 1, doesn't require any math
        else return F(n-1) * n 

        input size <- n (value of n, not the size of an array bc there isnt one)
        basic operation <- multiplication (F(n-1) * n)
            F(n) = F(n-1) * n   , n>0
        number of times multiplication is executed,
            M(n) = M(n-1) + 1   , for n>0
            M(0) = 0
        
        -> set up a recurrence ad initial condition
            M(n) = M(n-1) + 1   , for n>0
            M(0) = 0        // initial condition
        -> sovle the recurrence
            #1 Method of Forward Substitutions :-
                M(n) = M(n-1) + 1 -> #1
                M(0) = 0 -> initial condition

                * Substituting n=1 in equation #1 *
                M(1) = M(1-1) + 1
                     = M(0) + 1
                     = 0 + 1
                     = 1
                * Substitutin n=2 in equation #1 *
                M(2) = M(2-1) + 1
                     = M(1) + 1
                     = 2
                * Substitutin n=3 in equation #1 *
                M(3) = M(3-1) + 1
                     = M(2) + 1
                     = 4
                *
                *
                *  
                Identify a pattern -> 1 2 3 ...
                    M(n) = n 

            #2 Method of Backward Substitutions :-
                M(n) = M(n-1) + 1 -> #1
                
                * Substituting n-1 in place of n in equation #1 * 
                    M(n-1) = M(n-1-1) + 1
                           = M(n-2) + 1 -> #2
                * Substituting n-2 in place of n in equation #1 *
                    M(n-2) = M(n-2-1) + 1
                           = M(n-3) + 1 -> #3
                * Substituting #2 and #3 back into #1 * 
                    (#2) M(n) = [M(n-2) + 1] + 1
                              = M(n-2) + 2
                    (#3)      = [M(n-3) + 1] + 2
                              = M(n-3) + 3
                * Generalize - what is the emerging pattern *
                    M(n-i) + i
                    // make n-i = 0
                    // so... n = i
                    M(n-n) + n 
                    M(0) + n        // M(0) = 0
                * Thus *
                    M(n) = n

                           