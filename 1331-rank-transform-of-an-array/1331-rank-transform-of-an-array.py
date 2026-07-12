class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        result=[]
        original=arr[:]
        arr=sorted(set(arr))
        rank={}
        for i in range(len(arr)):
            rank[arr[i]]=i+1
        for score in original:
            result.append(rank[score])
        return result