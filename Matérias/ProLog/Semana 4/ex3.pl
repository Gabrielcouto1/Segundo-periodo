maior(A,B,C) :- A>B, C is A.
maior(A,B,C) :- B>A, C is B.

maior(A,B,C,D,E) :- A>B,A>C,A>D,E is A.
maior(A,B,C,D,E) :- B>A,B>C,B>D,E is B.
maior(A,B,C,D,E) :- C>A,C>B,C>D,E is C.
maior(A,B,C,D,E) :- D>A,D>B,D>C,E is D.

