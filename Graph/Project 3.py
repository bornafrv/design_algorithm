from heapq import heappush, heappop

def main():
    n, m, center = map(int, input().split())
    # intial graph
    graph = [[] for _ in range(n + 1)]

    for index in range(m):
        # new edge : 
        u, v, w = map(int, input().split())
        graph[u].append((v, w))
        graph[v].append((u, w))

    q = []
    heappush(q, (0, center))

    dist = [float('inf')] * (n + 1)

    dist[center] = 0

    while q:
        dValue, u = heappop(q)
        for v, w in graph[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                heappush(q, (dist[v], v))

    dValue = int(input())

    cntr = 0
    for nodeIndex in range(1, n + 1):
        if dist[nodeIndex] == dValue:
            cntr += 1


    for v in range(1, n + 1):
        for u, w in graph[v]:
            if v < u:
                flag = False
                if dist[v] < dValue < dist[v] + w:

                    kDist = w + dist[v] - dValue

                    if dValue <= dist[u] + kDist:
                        flag = True
                        cntr += 1

                if dist[u] < dValue < dist[u] + w:
                    kDist = w + dist[u] - dValue
                    if dValue <= dist[v] + kDist and (not flag or (dValue - dist[v]) + (dValue - dist[u]) != w):
                        cntr += 1
    print(cntr)


if __name__ == '__main__':
    main()
