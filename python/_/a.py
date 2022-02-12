for a in range (200,300):
    is_prime = True
    for i in range (2, a):
        if a % i == 0:
            is_prime = False
            break
    else:
        break

print("answer",a)
