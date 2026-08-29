SELECT teacher_id, 
       COUNT( distinct subject_id) as cnt
FROM Teacher
group by teacher_id;
