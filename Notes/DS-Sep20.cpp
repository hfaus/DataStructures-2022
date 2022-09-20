ALGORITHM BubbleSort (A[0....n-1])
    for i <- 0 to n-2 do
        for j <- 0 to n-2-i do 
            if A[j+1] < A[j]
                swap A[j] and A[j+i]

    basic operation: key comparison (if A[j+1] < A[j])
    non-recursive algorithm... do summation

    n-2 n-2-i          n-2
     E   E      1   =   E   n-2-i-0+1
    i=0 j=0            i=0
                      n-2
                    =  E  n-1-i
                      i=0
                      n-2        n-2
                    =  E    n-1 - E  i
                      i=0        i=0
                           n-2       n-2
                    = (n-2) E  1  -   E i
                           i=0       i=0
                    = (n-1)(n-2-0+1) - [(n-2)(n-2+1)]/2
                    = (n-1)(n-1) - [(n-2)(n-1)]/2
                    = (n-1)[(2n-2-n+2)/2]
              C(n)  = [(n-1)n]/2
    C(n) E theta(n/2)
--------------------------------------------------------------------------
BRUTE FORCE STRING MATCHING
Text -> 'n' characters 
Pattern -> 'm' characters 
    m <= n 
Find the substring that matches the pattern?
--------------------------------------------------------------------------
ALGORITHM BruteForceStringMatch(T[0...n-1],P[0...m-1])
    for i <- 0 to n-m do
        j <- 0 
        while j < m and P[j] = T[i+j] do 
            j <- j + 1
        if j = m retun i 
    return -1

Example:
    Text -> GOOD_MORNING
    Pattern -> IN
        G O O D _ M O R N I N G 
        X
        I N
          X
          I N
            X
            I N
            ... (comparing I and shifting pattern til a match)         
                         I N
                         (I was a match, so compared N, both matched so pattern was found)
    