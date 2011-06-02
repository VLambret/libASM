# Exemple de programme utilisé pour la recette 
lw $4, 0($0)
lw $4, 0($8) # Write after Write avec 1
addi $5, $4, 10 # Read after Write avec 2
sw $4, 0($8)
sub $4, $10, $5 # Write after Read avec 4 et 3
addi $31, $31, 4 # instruction indépendante
