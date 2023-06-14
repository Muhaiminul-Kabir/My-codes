x = [int(item) for item in input("Enter the list items : ").split()]

y = int(input('enter target'))

v = {}

for i in range(len(x)):
    if y-x[i] in v:
        print(f'{y-x[i]} {x[i]}')
    v[x[i]] = i;  
