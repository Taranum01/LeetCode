# Write your MySQL query statement below

SELECT e1.name AS Employee 
FROM employee e1 
JOIN
employee e2 
WHERE e1.managerid = e2.id 
AND e1.salary > e2.salary;