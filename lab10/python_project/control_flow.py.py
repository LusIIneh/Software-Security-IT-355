def secure_add(a, b):
    res, state = 0, 0
    while True:
        if state == 0: res = a + b; state = 1
        else: break
    return res

print("Sum:", secure_add(10, 20))
