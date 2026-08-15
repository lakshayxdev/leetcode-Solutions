# Write your MySQL query statement below
-- SELECT customer_id, COUNT(customer_id)
-- FROM Visits as v
-- LEFT JOIN Transactions as t
-- ON v.visit_id = t.visit_id
-- WHERE t.visit_id IS null
-- GROUP BY customer_id ORDER BY customer_id ASC;
SELECT customer_id, COUNT(customer_id) as count_no_trans
FROM Visits AS v
LEFT JOIN Transactions AS t
ON v.visit_id = t.visit_id
WHERE t.visit_id IS NULL
GROUP BY customer_id
ORDER BY COUNT(customer_id) ASC;
