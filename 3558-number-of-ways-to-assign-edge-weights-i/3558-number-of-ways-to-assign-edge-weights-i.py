class Solution:
    MOD = 10**9 +7

    def getMaxDepth(self,adj,node,parent):
        depth = 0

        for nei in adj[node]:
            if nei != parent:
                depth = max(depth,self.getMaxDepth(adj,nei,node) +1)
        return depth


    def assignEdgeWeights(self, edges: List[List[int]]) -> int:
        adj  = defaultdict(list)

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        max_depth = self.getMaxDepth(adj,1,-1)

        return pow(2,max_depth - 1, self.MOD)
        