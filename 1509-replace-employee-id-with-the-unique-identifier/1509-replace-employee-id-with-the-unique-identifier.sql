# Write your MySQL query statement below
SELECT eu.unique_id AS unique_id , e.name As name
FROM employees e # employees -> e 
LEFT JOIN employeeUNI eu # employeeUNI ->eu
ON e.id = eu.id
