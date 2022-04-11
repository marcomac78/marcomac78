f = open("Base.txt","r")
lines = f.readlines()
f.close()

NE = lines[1]

del lines[0:11]
del lines[:-11]


f = open("BaseNova.txt","w")
for line in lines:
    f.write(line)
f.close()
