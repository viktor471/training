import sys
for a in range (int(sys.argv[1]) ,int(sys.argv[2]) ):
    for i in range (2, a):
        if a % i == 0:
            break
    else:
        break

print("answer",a)
