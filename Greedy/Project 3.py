t = int(input())
for tt in range(t):
    n, q = input().split(" ")
    flowers = [int(i) for i in input().split()]
    orders = []
    for j in range(int(q)):
        orders.append([int(i) for i in input().split()])
        
    for ord in orders:
        if ord[0] == ord[1]:
            print("sad")
            continue
        size = 0
        for i in range(ord[0]-1, ord[1]):
            size += flowers[i]
        types = ord[1] - ord[0] + 1
        size -= types
        bouquet = [1] * types
        
        limit = -1
        finish = 0
        for i in range(types):
            if (bouquet[i] == flowers[ord[0]-1+i]):
                if size > 0:
                    bouquet[i] += 1
                    size -= 1
                    limit = i
                else:
                    limit = -1
                    finish = 1
                    print("sad")
                    break
                    
        if limit != -1:
            bouquet[i] += size
            finish = 1
            print("happy")
            continue
        if finish == 0:
            bouquet[0] += size
            if bouquet[0] == flowers[ord[0]-1]:
                bouquet[0] -= 1
                bouquet[1] += 1
                if bouquet[1] == flowers[ord[0]]:
                    bouquet[1] += 1
                    bouquet[0] -= 1
            else:
                finish = 1
                print("happy")
                continue
