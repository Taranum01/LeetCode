# Write your MySQL query statement below

SELECT e2.name AS Employee
FROM employee e1
INNER JOIN employee e2 on e1.id = e2.managerID
WHERE e1.salary < e2.salary