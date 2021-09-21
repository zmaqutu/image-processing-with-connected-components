import os
import sys
import fileinput



for edition in range(256):
    
    file_name = '../output_files/nfts/Home With Moon/Final NFT Collection/White First SVG/'+ 'nft_' + str(edition) + '.svg'

    with open(file_name,'r') as file:
        filedata = file.read()
    
    filedata = filedata.replace('width="3721.000000pt" height="2392.000000pt"','width="100%" height="100%"')
    

    with open(file_name,'w') as file:
        file.write(filedata)
        print(file_name + ' edit complete...')
