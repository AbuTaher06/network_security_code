edge(a,b).
edge(a,c).
edge(b,d).
edge(d,e).
path(A,B):-nextRoute(A,B,[]),write(B).
nextRoute(A,B,V):-
    edge(A,X),write(A),write('->'),
    not(member(X,V)),
    (   B=X;
    nextRoute(X,B,[A|V]);
    write(X)).


