# Write your MySQL query statement below
SELECT e.name ,b.bonus
FROM Employee e
LEFT JOIN Bonus b
ON e.empID = b.empID
WHERE b.bonus is NULL OR b.bonus <1000