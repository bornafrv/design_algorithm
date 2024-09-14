import sys
sys.set_int_max_str_digits(0)
n, m, k = input().split(" ")
k = int(k) - 1
n = int(n)
ballons = int(m) - n
ali = 1
turn = 0
while ballons > 0:
    for i in range(turn):
        if ((k - i - 1) >= 0) & (ballons > 0):
            ballons -= 1
        if ((k + i + 1) < n) & (ballons > 0):
            ballons -= 1
    if ballons > 0:
        ali += 1
        ballons -= 1
    turn += 1

print(ali)