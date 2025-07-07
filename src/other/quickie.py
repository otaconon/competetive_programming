arr = [0]
for i in range(5):
  temp = list(arr)
  for x in temp:
    arr.append(int(not x))
  
print(arr)