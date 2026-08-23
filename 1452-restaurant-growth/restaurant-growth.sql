WITH DailyTotals AS (
    SELECT 
        visited_on, 
        SUM(amount) AS total_amount
    FROM 
        Customer
    GROUP BY 
        visited_on
)
SELECT 
    visited_on,
    amount,
    average_amount
FROM (
    SELECT 
        visited_on,
        SUM(total_amount) OVER (
            ORDER BY visited_on 
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS amount,
        ROUND(
            AVG(total_amount) OVER (
                ORDER BY visited_on 
                ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
            ), 2
        ) AS average_amount,
        ROW_NUMBER() OVER (ORDER BY visited_on) AS row_num
    FROM 
        DailyTotals
) t
WHERE 
    row_num >= 7;