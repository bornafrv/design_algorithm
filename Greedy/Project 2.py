t = int(input())
for i in range(t):
    n = int(input())
    tank = [int(i) for i in input().split()]
    minimum = 100
    for x in tank:
        if x < minimum:
            minimum = x
    shot = 0

    if (minimum > 1):
        print(len(tank))
    else:
        tank.sort()
        while (len(tank) >= 2):
            if (tank[0] == 1):
                shot += 1
                tank.remove(tank[0])
                tank[0] -= 1
                if (tank[0] == 0):
                    tank.remove(tank[0])
            else:
                break
        print(shot + len(tank))
