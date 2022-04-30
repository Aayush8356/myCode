d = int(input())
n = int(input())
n = n % 7
if (d-n) < 0:
    print(d + (7-n))  
else:
    print(d - n)
