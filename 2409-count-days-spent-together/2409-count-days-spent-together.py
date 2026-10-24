class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str,
                          arriveBob: str, leaveBob: str) -> int:

        def convert(date_str):
            month, day = map(int, date_str.split('-'))

            days = [31, 28, 31, 30, 31, 30,
                    31, 31, 30, 31, 30, 31]

            return sum(days[:month - 1]) + day

        start1 = convert(arriveAlice)
        end1 = convert(leaveAlice)

        start2 = convert(arriveBob)
        end2 = convert(leaveBob)

        start = max(start1, start2)
        end = min(end1, end2)

        return max(0, end - start + 1)