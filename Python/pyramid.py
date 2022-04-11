blocks = int(input("Enter the number of blocks: "))

#
# Write your code here.
#	
height = 0
n = 0
soma = 0
aux = blocks



while (blocks != 0):
    soma = soma + n + 1
    if ((aux - soma) < 0):
        break

    n += 1
    height += 1
    blocks = blocks - n

print("The height of the pyramid:", height)