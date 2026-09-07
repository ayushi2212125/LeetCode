SELECT m.employee_id as employee_id,
       m.name,
       count(m.employee_id) as reports_count,
       round(AVG(e.age),0)as average_age
FROM Employees as e
Join Employees as m
ON e.reports_to= m.employee_id  
group by m.name,
         m.employee_id 
order by m.employee_id;    
