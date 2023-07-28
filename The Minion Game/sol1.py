def minion_game(string):
    vowels = ['A','E','I','O','U']
    # your code goes here
    
    #get all possible substrings
    all_ls=[]
    for i in range(len(string)):
        for j in range(1,len(string)+1):
            if(i<j):
                all_ls.append(string[i:j])
    
    kevin = 0
    stuart = 0
    #count score
    for s in all_ls:
        if(s[0] in vowels):
            kevin+=1
        else:
            stuart+=1
    
    if(kevin>stuart):
        print("Kevin {score}".format(score = kevin))
    elif(kevin<stuart):
        print("Stuart {score}".format(score = stuart))
    else:
        print("Draw")