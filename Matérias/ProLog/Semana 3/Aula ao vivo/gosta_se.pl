# john gosta de X se X gosta de vinho

likes(john,mary).
likes(mary,wine).
likes(penny,wine).
likes(paul,mary).


likes(john,X):-likes(X,wine).

# ?- likes(john,penny).
# true.