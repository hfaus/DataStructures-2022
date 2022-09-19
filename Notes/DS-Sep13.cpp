-> Common Recurrence Types: 
#1 Decrease-by-one
    T(n) = T(n-1) + f(n)
    ex- n! (factorial)
#2 Decrease-by-a-constant factor
    T(n) = T(n/b) + f(n)
    instance of size 'n' -> instance of size n/b
    assume n = b^k
        T(b^k) = T(b^(k-1)) + f(b^k)
               = T(b^(k-2)) + f(b^(k-1)) + f(b^k)
               = T(b^(k-3)) + f(b^(k-2)) + f(b^(k-1)) + f(b^k)
               = ..........
                        k
               = T(1) + E   f(b^j)
                       j=1
--------------------------------------------------------------------------
If f(n) = 1
    k
    E   f(b^j) = k              n = b^k
   j=1                          k = logbaseb(n)
               = logbaseb(n)
If f(n) = n
    k                                                   
    E   f(b^j) = b^1 + b^2 + b^3 + ... + b^k            EGeometric Progressions = a(1-r^n) / 1-r
   j=1                                                  
               = b(1-b^n) / 1-b
               = (b / 1-b)(1 - b^k)
               = (b / 1-b)(1 - n)
               = (b / b-1)(n - 1)
--------------------------------------------------------------------------
-> f(n) is a non-egative function defined on a set of natural numbers
-> f(n) is called eventually non-decrasing function if there exists some nbase0 (non-negative integer) 
    so that f(n) is non-decreasing on the interval [nbase0, infinity]
--------------------------------------------------------------------------
ex-
    f(n) = (n-100)^2
    n=1     (99)^2
    n=2     (98)^2
    n=3     (97)^2
    .
    .
    .
    n=98    (2)^2
    n=99    (1)^2
    n=100   (0)^2
    n=102   (1)^2
    n=103   (2)^2
    .
    .
    .
    f(n) is decreasing on the interval [0,100]
        [101,infinity] -> f(n) is non-decreasing
    THUS, f(n) is called a SMOOTH functio if it is eventually non-decreasing and f(2n) E theta(f(n))
--------------------------------------------------------------------------
ex-
    f(n) = nlogn
    f(2n) = 2nlog2n
          = 2nlog2 = 2nlogn
          = (2log2)n + 2(nlogn)
    [while logn is slow, nlogn is fast]
    f(2n) E theta(nlogn)
            ^
            |
    f(2n) E theta(f(n))
--------------------------------------------------------------------------
-> Smoothness Rule:
    let T(n) be eventually non-decreasing funciton and f(n) be a smooth function 
        If T(n) E theta(f(n)) for values fo 'n' that are powers of 'b' such that b >= 2
            then T(n) E theta(f(n))
--------------------------------------------------------------------------
-> Master's Theorem: 
    T(n) = aT(n/b) + f(n)
        for n = b^k
            k = 1,2,...
    T(1) = c
        where a >= 1, b >= 2, c >0

        If f(n) E theta(n^d) where d >= 0
            then T(n) E theta(n^d)          if a < b^d 
                        theta(n^d logn)     if a = b^d 
                        theta(n^log * b^a)  if a > b^d
            -> also true for bigO and omega notations
--------------------------------------------------------------------------
ex-
    T(n) = 3T(n/2) + sqrt(n)
        a = 3
        b = 2
        d = 1/2
            a > b^d
            3 > sqrt(2)
    T(n) E theta(n^(logbase2(3)))
