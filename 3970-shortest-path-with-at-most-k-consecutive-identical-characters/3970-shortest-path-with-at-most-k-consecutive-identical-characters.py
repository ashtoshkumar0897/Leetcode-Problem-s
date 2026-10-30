import heapq

class Solution:
    def shortestPath(self, n, edges, labels, k):
        adj = [[] for _ in range(n)]

        for u, v, wt in edges:
            adj[u].append((v, wt))

        dist = [[float('inf')] * (k + 1) for _ in range(n)]

        pq = [(0, 0, 1)]
        dist[0][1] = 0

        while pq:
            d, node, count = heapq.heappop(pq)

            if d > dist[node][count]:
                continue

            if node == n - 1:
                return d

            for adjNode, wt in adj[node]:

                newCount = count + 1 if labels[adjNode] == labels[node] else 1

                if newCount > k:
                    continue

                newDist = d + wt

                if newDist < dist[adjNode][newCount]:
                    dist[adjNode][newCount] = newDist
                    heapq.heappush(pq, (newDist, adjNode, newCount))

        return -1