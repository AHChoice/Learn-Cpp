# encoding:utf-8
import re

str1 = ''
with open('1.txt','r') as f:
    for line in f:
        #arr = re.split(r'[\s]+',line)
        arr = line.split()
        print(arr)
        
        for i in range(len(arr)):
            if re.match(r'^[\d\Wa-zA-Z]+',arr[i]):
                pass
            elif arr[i] not in str1:
                str1 += '//' + arr[i] + '\n\n'
       
            
with open('1ret.txt','w') as f:
    f.write(str1)
    
a = input('press enter to exit.')
