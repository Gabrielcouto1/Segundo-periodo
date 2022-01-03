influenciador(ivan,10).
influenciador(igor,30).

indica(igor,prolog).
indica(ivan,prolog).
indica(igor,bacon).

segue(ana,igor,3,ivan,10).
segue(a,ivan,10).

gosta(X,Y) :- segue(X,I,G),influenciador(I,F), T is F+G, T>=50,indica(I,Y).
gosta(X,Y) :- segue(X,I,G,Z,H),indica(I,Y),influenciador(I,F),indica(Z,Y),influenciador(Z,K), T is F+G+K+H, T>=50,indica(I,Y).