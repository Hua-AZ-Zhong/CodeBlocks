from py8583 import *
from py8583spec import *
from py8583spec import IsoSpec1987BCD

row_data = {}

with open('readtest.csv') as paces:
    column_headings = paces.readline().strip().split(',')
    column_headings.pop(0)

    for each_line in paces:
        row = each_line.strip().split(',')
        row_label = row.pop(0)
        row_data[row_label] = row


num_cols = len(column_headings)
print(num_cols, end=' -> ')
print(column_headings)


num_2mi = len(row_data['2mi'])
print(num_2mi, end=' -> ')
print(row_data['2mi'])

num_Marathon = len(row_data['Marathon'])
print(num_Marathon, end=' -> ')
print(row_data['Marathon'])

# Len = 0x0093
# TPUD = 0x600009A8EB
# Version = 0x1307
#orig_message = "0093600009A8EB130702207024078024C0800D19062220307130021338962700000000000746740509522911005200010009143706222030713002133896D29112201139991021202020202020323135323030353031303432313031383036323235323901560015313530333139303031303432333731002030323030303531373037303133303034323431367777D86AC9A75700"
orig_message = "02207024078024C0800D19062220307130021338962700000000000746740509522911005200010009143706222030713002133896D29112201139991021202020202020323135323030353031303432313031383036323235323901560015313530333139303031303432333731002030323030303531373037303133303034323431367777D86AC9A75700"

#message1 = Iso8583(row_data['2mi'][0], IsoSpec1987BCD())
message1 = Iso8583(Str2Bcd(orig_message), IsoSpec1987BCD())
