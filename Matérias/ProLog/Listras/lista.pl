w([ [Peso,Altura] ],[X,Y],[[Peso,Altura]]) :- Peso>X,Altura>Y,!.
w( [ [_,_]],[_,_], [] ).


w([[Peso,Altura]|T ],[X,Y],[[Peso,Altura]|S]) :- Peso>X,Altura>Y,w(T,[X,Y],S),!.

w([[_,_]|T ],[X,Y],S) :-w(T,[X,Y],S),!.