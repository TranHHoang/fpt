import re
sourcePath = input('Enter the path of source code: ')

ifStmt = re.compile('if[ ]*([^\[]+)\[(\d+)\].*==.*(\d+):')
bankselStmt = re.compile('use[ ]*(\w+)') # use trisd
movlwStmt = re.compile('[w|W][ ]*=[ ]*[b|B]\'([01]+)\'') # w = b'100001'
movwfStmt = re.compile('(\w+)[ ]*=[ ]*[w|W]') # portd = w
clearStmt = re.compile('(\w+)[ ]*=[ ]*0') # trisd = 0
bitStmt = re.compile('(\w+)\[(\d)\][ ]*=[ ]*(\d)') # portd[0] = 1

result = 'INCLUDE <P16F887.INC>\n\n'

with open(sourcePath) as f:
    for line in f:
        match = ifStmt.match(line.strip())
        if match is not None:
            # btfsc
            result += '\tBTFSC\t' if match.group(3) == '1' else '\tBTFSS\t'
            result += match.group(1).upper() + ', ' + match.group(2) + '\n'
            continue

        match = bankselStmt.match(line.strip())
        if match is not None:
            # btfsc
            result += '\tBANKSEL\t' + match.group(1).upper() + '\n'
            continue
        
        match = movlwStmt.match(line.strip())
        if match is not None:
            result += '\tMOVLW\t' + 'B\'' + match.group(1) + '\'\n'
            continue
        
        match = movwfStmt.match(line.strip())
        if match is not None:
            result += '\tMOVWF\t' + match.group(1).upper() + '\n'
            continue

        match = clearStmt.match(line.strip())
        if match is not None:
            result += '\tCLRF\t' + match.group(1).upper() + '\n'
            continue

        match = bitStmt.match(line.strip())
        if match is not None:
            result += '\tBSF\t' if match.group(3) == '1' else '\tBCF\t'
            result += match.group(1).upper() + ', ' + match.group(2) + '\n'
            continue
        
        result += line
    

result += """ 
Delay
    DECFSZ  20h
    GOTO    Delay
    RETURN

DelaySlower
    DECFSZ  20h
    GOTO    DelaySlower
    DECFSZ  21h
    GOTO    DelaySlower
    RETURN
"""

result += '\nEND'
print(result)