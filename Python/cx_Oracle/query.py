# query.py
# Reference to URL https://cx-oracle.readthedocs.io/en/latest/user_guide/introduction.html

import cx_Oracle

userpwd = "BOCSWT"
# Establish the database connection
#connection = cx_Oracle.connect("hr", userpwd, "dbhost.example.com/orclpdb1")
connection = cx_Oracle.connect("bocswt", userpwd, "192.168.6.248/XE")

# Obtain a cursor
cursor = connection.cursor()

# Data for binding
instId = "3000"
userId = "      3000"

# Execute the query
sql = """SELECT *
         FROM shcbin
         WHERE institutionid = :p1 AND userbinid = :p2"""
cursor.execute(sql, p1 = instId, p2 = userId)

# Loop over the result set
for row in cursor:
    print(row)
