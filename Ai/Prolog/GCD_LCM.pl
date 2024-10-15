gcd(A,0,A).
gcd(A,B,Result):-
    B>0,
    A1 is B,
    B1 is A mod B,
    gcd(A1,B1,Result).
lcm(A,B,Result):-
gcd(A,B,GCD),
    Result is (A*B)/GCD.


