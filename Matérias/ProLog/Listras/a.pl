c([L1,C1],[L2,C2]) :- L2 is L1 +1, C2 is C1 +2;
                    L2 is L1 -1, C2 is C1 +2;
                    L2 is L1 +1, C2 is C1 -2;
                    L2 is L1 -1, C2 is C1 -2;        
                    L2 is L1 +2, C2 is C1 +1;
                    L2 is L1 -2, C2 is C1 +1;
                    L2 is L1 +2, C2 is C1 -1;
                    L2 is L1 -2, C2 is C1 -1.

move([L1,C1],[L2,C2],LMin,LMax,CMin,CMax) :- c([L1,C1],[L2,C2]), 
                                 L2>=LMin,
                                 L2=<LMax,
                                 C2>=CMin,
                                 C2=<CMax. 
 
%boot
tour(X) :- tour([ [1,1] ],X).

% Finalizacao
tour([H|T],[H|T]) :- length([H|T],25),!.

% Passo....
tour([H|T],Resposta)  :- move(H,Novo,1,5),
                           \+member(Novo,T),
                           tour([Novo,H|T],Resposta).

openWalk(Walk,LinhaMin,LinhaMax,ColMin,ColMax) :- move(H,Novo,LMin,LMax,CMin,CMax),
                                                  \+member(Novo,T),
                                                  tour([Novo,H|T],Resposta).