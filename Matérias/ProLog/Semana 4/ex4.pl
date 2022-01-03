somaDigito(N,N) :- N<10.

somaDigito(N,S) :- N>=10,
                   T is N mod 10,
                   somaDigito(N//10,S2),
                   T+S2<10,
                   S is T+S2.

somaDigito(N,S) :- N>=10,
                   T is N mod 10,
                   somaDigito(N//10,S2),
                   T+S2>=10,
                   somaDigito(T+S2,S).      