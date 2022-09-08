Ex2
    T(n) = 2T(n-1) + 1      , for n>1
    T(1) = 1
Method of forward sub:
    T(2) = 2T(2-1) + 1
         = 2T(1) + 1
         = 2 * 1 + 1
         = 3
    T(3) = 2T(3-1) + 1
         = 2T(2) + 1
         = 2 * 3 + 1
         = 7
    T(4) = 2T(4-1) + 1
         = 2T(3) + 1
         = 2 * 7 + 1
         = 15
    ...
    Pattern: 3,7,15,...
    T(n) = 2^n - 1      , for n=1,2,3,4,...
Method of backward sub:
    T(n) = 2T(n-1) + 1      , for n>1
        -> eq1
    T(1) = 1
    [Substitute n = n-1 in eq1]
    T(n-1) = 2T(n-1-1) + 1
    T(n-1) = 2T(n-2) + 1
        -> eq2
    [Substitute n=n-2 in eq1]
    T(n-2) = 2T(n-2-1) + 1
           = 2T(n-3) + 1
        -> eq3
    [Substituting eq2 and eq3 in eq1]
    T(n) = 2[2T(n-2) + 1] + 1
         = 4T(n-2) + 2 + 1
         = 4T(n-2) + 3
         = 4[2T(n-3) + 1] + 3
         = 8T(n-3) + 4 + 3
         = 8T(n-3) + 7
    ...
    [Generalize using i]
        = 2^i T(n-i) + (2^i - 1)
        -> n-i = 1
           i = n-1
        = 2^(n-1) T(n-n-1) + (2^(n-1) - 1)
        = 2^(n-1) T(1) + 2^(n-1) - 1
        = 2^(n-1) + 2^(n-1) - 1
        = 2^n - 1
    T(n) = 2^n - 1 E theta(2^n)

ex3
    T(n) = T(n-1) + n
    T(0) = 0
Method of backward sub:
    [Substitute k = k-1 in eq1]
    T(n-1) = T(n-2) + n - 1
        -> eq2
    [Substitues k = k-2 in eq1]
    T(n-2) = T(n-3) + n-2
        -> eq3
    [Substitues k = k-2 in eq1]
    T(n) = [T(n-2) + n - 1] + n 
         = T(n-2) + (n-1) + n 
         = T(n-3) + (n-2) + (n-1) + n 
         = ...
    [Generalize using i]
         = T(n-i) + (n-i+1) + (n-i+2) + ... + n
            -> n - i = 0
               i = n 
        = T(n-n) + 1 + 2 + ... + n
        = 0 + 1 + 2 + ... + n 
        = 1 + 2 + ... + n 
            -> sum of all natural numbers 
    T(n) = n(n+1) / 2

ex4
    T(n) = T(n/2) + 2n
    T(1) = 2
    bc we have a fraction, to make less complicated we will eliminate the denominator
    let n = 2^k     , k > 0 and k is an int 
    T(2^k) = T(2^k / 2) + 2 * 2^k
           = T(2^(k-1)) + 2 * 2^k
            -> eq1
Method of backward sub:
    [Substitute k = k-1 in eq1]
    T(2^(k-1)) = T(2^(k-1-1)) + 2 * 2^(k-1)
               = T(2^(k-2)) + 2 * 2^(k-1)
                -> eq2
    [Substitues k = k-2 in eq1]
    T(2^(k-2)) = T(2^(k-2-1)) + 2 * 2^(k-2)
               = T(2^(k-3)) + 2 * 2^(k-2)
                -> eq3
    [Substitute eq2 and eq3 in eq1]
    T(2^k) = [T(2^(k-2)) + 2 * 2^(k-1)] + 2 * 2^k
           = [T(2^(k-3)) + 2 * 2^(k-2)] + 2 * 2^(k-1) + 2 * 2^k
           = ...
    [Generalize using k instead of i (bc we already have k and n, adding i would be too many unknowns)]
           = T(2^(k-k)) + 2 * 2^(k-k+1) + 2 * 2^(k-k+2) + 2 + ... + 2 * 2^k
           = T(1) + 2 * 2^1 + 2 * 2^2 + ... + 2 * 2^k
           = 2 * 2^0 + 2 * 2^1 + 2 * 2^2 + ... + 2 * 2^k
           = 2[2^0 + 2^1 + 2^2 + ... + 2^k]
           = 2[2^(k+1) - 1]                         -> used a formula (E = summation) [n over E under i = 0] 2^i = 2^(n+1) - 1
           = 2 * 2^k * 2 - 2
           = 4(2^k) - 2
    T(n) = 4n - 2 E theta(n)

Linear second-order recurrence relations with constant coefficents
    aT(n) + bT(n-1) + cT(n-2) = f(n)
        a,b,c -> real numbers
            a != 0

    -> if f(n) = 0
       aT(n) + bT(n-1) + cT(n-2) = 0
       -> homogeneous case 

    -> if f(n) != 0
       aT(n) + bT(n-1) + cT(n-2) = f(n)
       -> inhomogeneous case  

    Cannot use forward or backward sub... need to find the characteristic equation
        ar^2 + br + c = 0
            -> replaced T(n) with r
        where r = [-b +- sqrt(b^2 - 4ac)] / 2a

    #1 If the roots are real and distinct, (rsub1 and rsub2)
        T(n) = alpha (rsub1)^n + beta (rsub2)^n
            -> wehre alpha, beta -> arbitrary
    #2 If the roots are equal,
        rsub1 = rsub2 = r 
        T(n) = alpha r^n + beta nr^n 
    #3 If the roots are complex and distinct
        T(n) = gamma^n [alpha cosn(theta) + beta sinn(theta)]
            -> where gamma = sqrt(u^2 + v^2)
            -> where theta = arctan(v/u)

ex1 
    f(n) - f(n-1) - f(n-2) = 0
    f(0) = 0
    f(1) = 1

    [Find the characteristic equation]
    r^2 - r - 1 = 0

    [Find the roots]
    a = 1
    b = -1
    c = -1
    r = [-(-1) +- sqrt((-1)^2 - 4(1)(-1))] / 2(1)
      = [1 +- sqrt(1 + 4)] / 2
      = [1 +- sqrt(5)] / 2
    rbase1 = [1 + sqrt(5)] / 2      rbase2 = [1 - sqrt(5)] / 2
        -> the roots are real and distinct
    f(n) = alpha ([1 + sqrt(5)] / 2)^n + beta ([1 - sqrt(5)] / 2)^n 
        -> general solution

    f(0) = 0
    f(0) = alpha ([1 + sqrt(5)] / 2)^0 + beta ([1 - sqrt(5)] / 2)^0
         = alpha * 1 + beta * 1
      0  = alpha + beta
      alpha = -beta 

    f(1) = 1
    f(1) = alpha ([1 + sqrt(5)] / 2)^1 + beta ([1 - sqrt(5)] / 2)^1
      1 = ...
      alpha = 1/(sqrt(5))

    [Particular solution]
        f(n) = 1/(sqrt(5)) ([1 + sqrt(5)] / 2)^n - 1/(sqrt(5)) ([1 - sqrt(5)] / 2)^n





             