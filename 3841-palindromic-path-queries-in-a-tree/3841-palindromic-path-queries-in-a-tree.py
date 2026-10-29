
class Solution:
    def palindromePath(self, n, edges, s, queries):
        adj = [[] for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        tin = [0] * n
        tout = [0] * n
        depth = [0] * n

        LOG = n.bit_length()
        up = [[-1] * LOG for _ in range(n)]

        euler = [0] * (2 * n)
        timer = 0

        # Euler Tour + DFS + Binary Lifting
        def dfs(node, parent, d):
            nonlocal timer

            depth[node] = d
            up[node][0] = parent

            tin[node] = timer
            euler[timer] = 1 << (ord(s[node]) - ord('a'))
            timer += 1

            for child in adj[node]:
                if child != parent:
                    dfs(child, node, d + 1)

            tout[node] = timer
            euler[timer] = 1 << (ord(s[node]) - ord('a'))
            timer += 1

        dfs(0, -1, 0)

        # Build Binary Lifting Table
        for j in range(1, LOG):
            for node in range(n):
                p = up[node][j - 1]
                if p != -1:
                    up[node][j] = up[p][j - 1]

        # LCA
        def getLCA(u, v):
            if depth[u] < depth[v]:
                u, v = v, u

            diff = depth[u] - depth[v]

            for j in range(LOG):
                if diff & (1 << j):
                    u = up[u][j]

            if u == v:
                return u

            for j in range(LOG - 1, -1, -1):
                if up[u][j] != up[v][j]:
                    u = up[u][j]
                    v = up[v][j]

            return up[u][0]

        # Segment Tree
        size = 1
        while size < 2 * n:
            size *= 2

        seg = [0] * (2 * size)

        for i in range(2 * n):
            seg[size + i] = euler[i]

        for i in range(size - 1, 0, -1):
            seg[i] = seg[2 * i] ^ seg[2 * i + 1]

        # Point Update
        def update(index, val):
            pos = size + index
            seg[pos] = val

            pos //= 2
            while pos:
                seg[pos] = seg[2 * pos] ^ seg[2 * pos + 1]
                pos //= 2

        # Range XOR Query [left, right]
        def rangeXOR(left, right):
            left += size
            right += size

            ans = 0

            while left <= right:
                if left % 2 == 1:
                    ans ^= seg[left]
                    left += 1

                if right % 2 == 0:
                    ans ^= seg[right]
                    right -= 1

                left //= 2
                right //= 2

            return ans

        # Process Queries
        result = []

        for q in queries:
            parts = q.split()

            if parts[0] == "update":
                node = int(parts[1])
                ch = parts[2]

                s = s[:node] + ch + s[node + 1:]

                mask = 1 << (ord(ch) - ord('a'))

                update(tin[node], mask)
                update(tout[node], mask)

            else:
                u = int(parts[1])
                v = int(parts[2])

                lca = getLCA(u, v)

                mask = (
                    rangeXOR(0, tin[u])
                    ^ rangeXOR(0, tin[v])
                    ^ (1 << (ord(s[lca]) - ord('a')))
                )

                result.append((mask & (mask - 1)) == 0)

        return result
