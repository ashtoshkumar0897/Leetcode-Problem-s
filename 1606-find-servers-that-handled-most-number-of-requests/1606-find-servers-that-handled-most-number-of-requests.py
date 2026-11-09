class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        n = len(arrival)
        if n <= k :
            return list(range(n))

        busy = [(t + d) * k + x for x,t,d in zip(range(k),arrival,load)]
        heapify(busy)
        free,handled =[],list(range(k))

        i = k
        while i< n:
            t = arrival[i]
            done = (t + 1) * k
            if busy and busy[0] < done:
                job = heappop(busy)
                while busy and busy[0] < done:
                    heappush(free,i + (job - i) % k)
                    job = heappop(busy)
                x = heappushpop(free, i + (job - i) % k ) % k

            elif free:
                x = heappop(free) % k
            else:
                i = bisect_left(arrival,busy[0] // k, i + 1)
                continue
            heappush(busy,(t + load[i]) * k + x)
            handled.append(x)

            i += 1
        return multimode(handled)

        