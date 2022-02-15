quadrado(X,Y) :- Y is X*X.

auxiliar(0) :- !.

primo(2) :- !.
primo(3) :- !.
primo(X) :- quadrado(X,Z),
			W is Z-1,
            Y is W mod 24,
            auxiliar(Y).