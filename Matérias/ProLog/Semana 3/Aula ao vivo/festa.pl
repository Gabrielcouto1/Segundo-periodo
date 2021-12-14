#"Uma pessoa feliz e com dinheiro faz uma festa de aniversario"
#Quem faz essa festa?

feliz(ana).
feliz(joao).
feliz(maria).

temdinheiro(ana).
temdinheiro(maria).
temdinheiro(joao).
temdinheiro(jose).

aniversario(maria).
aniversario(joao).
aniversario(jose).

faz_festa(X) :- temdinheiro(X),feliz(X),aniversario(X).

# ?- feliz(X),temdinheiro(X),aniversario(X).
# X = joao

# ou 

#