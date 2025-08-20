# Write your MySQL query statement below
SELECT DISTINCT author_id AS id # rename  colum using AS 
FROM views
WHERE author_id = viewer_id
ORDER BY id  # ORDER BY -> print result in assinding order
