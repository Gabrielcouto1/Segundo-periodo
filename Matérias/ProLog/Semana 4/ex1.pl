gosta(aa,cc).
gosta(bb,cc).
gosta(cc,aa).
gosta(cc,bb).

triangulo(A,B,C) :- gosta(A,C),gosta(B,C),gosta(C,A),gosta(C,B).