SELECT v.customer_id, count(*) as count_no_trans
FROM Visits as v
LEFT JOIN Transactions as t
ON v.visit_id = t.visit_id
WHERE t.transaction_id is null
group by v.customer_id;
