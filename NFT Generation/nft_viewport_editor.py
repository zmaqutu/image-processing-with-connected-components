import os
import sys
import fileinput

with open('nft_161.svg','r') as file:
    filedata = file.read();

filedata = filedata.replace('width="3721.000000pt" height="2392.000000pt"','width="100%" height="100%"')

with open('nft_161.svg','w') as file:
    file.write(filedata)
