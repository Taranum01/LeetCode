# Write your MySQL query statement below


UPDATE Salary SET sex = IF(sex='f', 'm', 'f');

# UPDATE Salary 
# SET sex= 
# CASE sex
#     WHEN 'f' THEN 'm'
#     WHEN 'm' THEN 'f'
# END;
