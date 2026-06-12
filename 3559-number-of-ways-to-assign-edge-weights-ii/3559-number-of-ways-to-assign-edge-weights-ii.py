from math import log2

class Solution:
    MOD = 10**9 + 7

    def dfs(self, node, parent):
        self.ancestor[node][0] = parent

        for nei in self.adj[node]:
            if nei == parent:
                continue

            self.depth[nei] = self.depth[node] + 1
            self.dfs(nei, node)

    def buildAncestorTable(self):
        for j in range(1, self.cols):
            for node in range(self.n):
                prev = self.ancestor[node][j - 1]

                if prev != -1:
                    self.ancestor[node][j] = self.ancestor[prev][j - 1]

    def findLCA(self, u, v):
        if self.depth[u] < self.depth[v]:
            u, v = v, u

        # Lift u to the same depth as v
        k = self.depth[u] - self.depth[v]

        for j in range(self.cols):
            if k & (1 << j):
                u = self.ancestor[u][j]

        if u == v:
            return u

        # Lift both nodes together
        for j in range(self.cols - 1, -1, -1):
            if self.ancestor[u][j] == -1:
                continue

            if self.ancestor[u][j] != self.ancestor[v][j]:
                u = self.ancestor[u][j]
                v = self.ancestor[v][j]

        return self.ancestor[u][0]

    def assignEdgeWeights(self, edges, queries):
        self.n = len(edges) + 1
        self.cols = int(log2(self.n)) + 1

        self.adj = [[] for _ in range(self.n)]

        for u, v in edges:
            u -= 1
            v -= 1

            self.adj[u].append(v)
            self.adj[v].append(u)

        self.depth = [0] * self.n
        self.ancestor = [[-1] * self.cols for _ in range(self.n)]

        self.dfs(0, -1)
        self.buildAncestorTable()

        # Precompute powers of 2
        pow2 = [1] * (self.n + 1)

        for i in range(1, self.n + 1):
            pow2[i] = (2 * pow2[i - 1]) % self.MOD

        result = []

        for u, v in queries:
            u -= 1
            v -= 1

            lca = self.findLCA(u, v)

            d = self.depth[u] + self.depth[v] - 2 * self.depth[lca]

            if d == 0:
                result.append(0)
            else:
                result.append(pow2[d - 1])

        return result