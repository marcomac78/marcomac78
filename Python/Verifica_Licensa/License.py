# Python program to
# demonstrate readline()

# L = ["Geeks\n", "for\n", "Geeks\n"]

# Writing to a file
# file1 = open('QMRJO2.txt', 'w')
# file1.writelines((L))
# file1.close()

# Using readline()
file1 = open('C:/Users/F8012852/Documents/Programas/Python/Verifica_Licensa/QMRJO2.txt', 'r')
file2 = open('C:/Users/F8012852/Documents/Programas/Python/Verifica_Licensa/QMRJO2_1.txt', 'w')
lines_to_print = [0,13]
for index, line in enumerate(file1):
    if(index in lines_to_print):
        if(index == 0):
            print(line.lstrip()[27:33])
            file2.writelines((line.lstrip()[27:33]))
            continue
        print(line.lstrip())
        file2.writelines((line.lstrip()))
file1.close()
file2.close()
