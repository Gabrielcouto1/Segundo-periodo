par(0) :- fail.
par(N) :- mod(N,2) =:= 0.

pot(_,0,R) :- R is 1,!.
pot(B,1,R) :- R is B,!.
 
pot(B,E,R) :- par(E), M is E//2,
              pot(B,M,R1),
              R is R1*R1,!;
              M is E//2,
              pot(B,M,R1),
              R is R1*R1*B,!.

%pot(B,E,R,M) :- pot(B,E,Rt),R is Rt mod M.

pot(_,0,R,_) :- R is 1,!.
pot(B,1,R,M) :- R is B mod M,!.

pot(B,E,R,M) :- par(E),
                Meio is E//2,
                pot(B,Meio,R1),
                R is R1*R1 mod M,!;
                Meio is E//2,
                pot(B,Meio,R1,M),
                R is R1*R1*B mod M,!.

decpot2(N,0,N) :- \+par(N).

decpot2(N,E,Impar) :- par(N),
                     Nr is N//2,
                     decpot2(Nr,Er,Impar),
                     E is Er+1.

dec(P,N,D) :- P1 is P -1,
              decpot2(P1,N,D).

test1M1(1,_) :- !.

test1M1(MU,Mod) :- MU is Mod-1.

primo(P,W) :- dec(P,_,I),
              pot(W,I,Pot,P),
              test1M1(Pot,P).