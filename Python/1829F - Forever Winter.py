from collections import defaultdict

wt = int(input())
ans1 = []
ans2 = []
for _ in range(wt):
        
    w,t = input().split()
    g = defaultdict(list)

    x1= None
    y1 = None

    for _ in range(int(t)):
        x,y = input().split()
        g[x].append(y)
        g[y].append(x)

    key_list = list(g.keys())
    val_list = list(g.values())


    for i in g.values():
        if(len(i) == 1):
            
            position = val_list.index(i)
            
        
            g[i[0]].remove(key_list[position]); 
            
            y1 =  len(g[i[0]]) 
            for j in g[i[0]]:
                if(len(g[j]) > 1):
                    x1 = len(g[j])
                    break
            break
    ans1.append(x1)
    ans2.append(y1)
for x, y in zip(ans1, ans2):
    print(f'{x} {y}')



