#!/usr/bin/env python

import socket
import sys
import struct
import os

from py8583 import Iso8583, MemDump, Str2Bcd

    
from py8583spec import IsoSpec1987BCD



HOST = ''
PORT = 5000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    s.bind((HOST, PORT))
except socket.error as msg:
    print ('Bind failed. Error Code : ' + str(msg[0]) + ' Message ' + msg[1])
    sys.exit()
    

s.listen(10)


while True:
    try:
        print ('Waiting for connections')
        conn, addr = s.accept()
        print ('Connected: ' + addr[0] + ':' + str(addr[1]))
        data = conn.recv(4096)
        MemDump("Received:", data)
        
        Len = struct.unpack_from("!H", data[:2])[0]
        
        if(Len != len(data) - 2):
            print("Invalid length {0} - {1}".format(Len, len(data) - 2))
            conn.close()
            continue
        
        print ('Message Header is [ ' + data[:2].hex() + ' ]')
        print ('Message TPDU is [ ' + data[2:7].hex().upper() + ' ]')
        # TODO LRI
        print ('Message POS Version is [ ' + data[7:9].hex().upper() + ' ]')
        print ('Message MTI is [ ' + data[9:11].hex().upper() + ' ]')
        print ('Message Bitmap is [ ' + data[11:19].hex().upper() + ' ]')
        # input data should contains mti,bitmap,body
        IsoPacket = Iso8583(data[9:], IsoSpec1987BCD())
        print ('hello2')
        
        IsoPacket.PrintMessage()
        
        IsoPacket.MTI("0210")
        
        IsoPacket.Field(39, 1)
        IsoPacket.FieldData(39, "00")
        IsoPacket.Field(2, 0)
        IsoPacket.Field(35, 0)
        IsoPacket.Field(52, 0)
        IsoPacket.Field(60, 0)
         
        print("\n\n\n")
        IsoPacket.PrintMessage()
        data = IsoPacket.BuildIso()
        data = struct.pack("!H", len(data)) + data
         
        MemDump("Sending:", data)
        conn.send(data)
        
        
    except Exception as ex:
        print(ex)
        
    conn.close()
    
s.close()
sys.exit()
