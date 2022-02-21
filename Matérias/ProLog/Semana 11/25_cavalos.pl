r1(A,AP,D) :- AP is (3**(A+3) + D*17) mod 29.

r2(A,B,A,D) :- r1(A,AP,D),
               r1(B,BP,D),
               AP>BP,!.

r2(_,B,B,_).

r3([U],U,_).
r3([H|T],Maior,D) :- r3(T,MR,D),r2(H,MR,Maior,D).

% Garante que a corrida tem no maximo 5 cavalos
corre(L,_,_) :- length(L,X),X>5,!,fail.

corre([U],[U],_) :-!.
corre(Cavalos,[Ganhador|Resto],D) :- r3(Cavalos,Ganhador,D),
                                     delete(Cavalos,Ganhador,CavalosResto),
                                     corre(CavalosResto,Resto,D).