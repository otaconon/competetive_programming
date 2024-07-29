dane = input().split()
a, b, c = float(dane[0]), float(dane[1]), float(dane[2])

if a == 0 and b == c:
    print("NWR")
elif a == 0:
    print("BR")
else:
    print(round((c - b)/a, 2))
