CHAPTER 3: BRUTE FORCE AND EXHAUSTION SEARCH
-> Brute force is a straighforward approach to sovling a problem
--------------------------------------------------------------------------
ALGORITHM SelectionSort
    for i <- 0 to n-2 do 
        min <- i 
        for j <- i + 1 to n-1 do 
            if A[j] < A[min]    min <- j 
        swap A[i] and A[min]

    basic operation: key comparison (if A[j] < A[min])
    n-2 n-1
     E   E      1
    i=0 j=i+1

    [side note: solve j first]
    n-2 n-1        n-2
     E   E      1 = E   n-1 - (i+1) + 1
    i=0 j=i+1      i=0
                  = .   n - i - 1
                  = .   [(n-1) - i]
                           n-2     n-2
                  = (n-1)   E   1 - E   i 
                           i=0     i=0
                  = (n-1)(n-2-0+1) - [(n-2)(n-2+1) / 2]
                  = (n-1)^2 - [(n-1)(n-2) / 2]
                  = n(n-1) / 2
    n(n-1) / 2 E theta(n^2)
    SelectionSort is a theta(n^2) algortihm on all inputs
    [Side note: the efficiency class will include the FASTEST function AND theta is the most common bc occurs when the function is in our formula]
    Number of key swaps = theta(n)
--------------------------------------------------------------------------