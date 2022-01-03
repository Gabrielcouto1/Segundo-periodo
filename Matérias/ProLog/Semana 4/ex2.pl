gosta(aa,cc).
gosta(bb,cc).
gosta(cc,aa).

gosta(ee,ff).
gosta(dd,ff).
gosta(ff,dd).

romance(A,B,C) :- gosta(A,C),gosta(B,C),gosta(C,A).
romance(A,B,C) :- gosta(A,C),gosta(B,C),gosta(C,B).

