# Write your MySQL query statement below

SELECT s.name
FROM SalesPerson s
WHERE sales_id 
NOT IN (
    SELECT o.sales_id
    FROM Company c, Orders o
    WHERE o.com_id = c.com_id
    AND c.name = 'RED')