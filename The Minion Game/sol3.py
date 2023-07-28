vowels = ['A','E','I','O','U']

def minion_game(string):# n solution as we don't need to actually make the combinations
    p1,p2 = 0,0
    for i in range(len(string)):
        if string[i] in vowels:
            p1+=len(string)-i
        else:
            p2+= len(string)-i  
    if p1 > p2:
        print(f'Kevin {p1}')
    elif p1 < p2:
        print(f'Stuart {p2}')
    else:
        print('Draw')