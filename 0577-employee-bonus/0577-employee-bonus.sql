SELECT Employee.name, Bonus.bonus
From Employee
left Join Bonus
ON Employee.empId = Bonus.empId
WHERE Bonus.bonus<1000 or Bonus.bonus is null;
