class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        
        asteroids.sort()
        
        for m in asteroids:
            if mass <m:
                return False
            elif mass >=1e5:
                return True
            mass +=m
        return True

