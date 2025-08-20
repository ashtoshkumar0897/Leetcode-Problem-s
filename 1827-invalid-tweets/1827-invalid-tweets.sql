# Write your MySQL query statement below

SELECT tweet_id
FROM Tweets
where CHAR_LENGTH(content) > 15

# LENGTH() -> BYTES
#  CHAR_LENGTH -> Char
