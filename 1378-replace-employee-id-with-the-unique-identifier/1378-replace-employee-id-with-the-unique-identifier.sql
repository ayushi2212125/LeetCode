SELECT unique_id,name
FROM Employees as e
LEFT JOIN EmployeeUNI as u
on e.id = u.id;
