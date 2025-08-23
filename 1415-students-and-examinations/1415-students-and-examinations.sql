SELECT
    s.student_id,
    s.student_name,
    sub.subject_name, -- Changed from subject_id for consistency
    COUNT(e.student_id) AS attended_exams -- Counting on e.student_id is slightly more conventional
FROM
    Students s
CROSS JOIN
    Subjects sub
LEFT JOIN
    Examinations e ON s.student_id = e.student_id AND sub.subject_name = e.subject_name
GROUP BY
    s.student_id, sub.subject_name -- No need to group by student_name as student_id is the primary key
ORDER BY
    s.student_id, sub.subject_name;