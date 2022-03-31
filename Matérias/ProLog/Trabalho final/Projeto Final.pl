geraBola(X) :- random_between(0,1,X).

removeBolaAleat([X,Y], Bola) :- random_between(0,1,X), X =:= 0, Bola is X, !;
                                Bola is Y.

probabAleatoria(1, Red, Green) :- geraBola(X), Bolas = [X, 1], removeBolaAleat(Bolas, Removida), 
                                  Removida =:= 0, Red is 0, Green is 1, !;
                                  Red is 1, Green is 0, !.

probabAleatoria(X, Red, Green) :-   geraBola(Y), L = [Y, 1], removeBolaAleat(L, Removida), 
                                    Removida =:= 1,
                                    X1 is X - 1, probabAleatoria(X1, R, Green), Red is R + 1, !;
                                    X1 is X - 1, probabAleatoria(X1, Red, G), Green is G + 1.

simulacao(1) :- probabAleatoria(100000, R1, G1), Total is R1 + G1, R is R1/Total, G is G1/Total,
                write('Vermelho: '),Red is R*100,write(Red),writeln('%'),
                write('\nVerde: '),Green is G*100,write(Green),write('%').
