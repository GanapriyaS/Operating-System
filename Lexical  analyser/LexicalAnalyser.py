class LexicalAnalyser:
    def __init__(self):
        self.analyser={"keyword":[],"integer":[],"realNumber":[],"identifier":[],"specialCharacter":[],"operator":[]}
        self.delimiter=[' ','=','+','-','*','/',':','}','{','[',']','(',')','%','<','~',',',';','>','!','^']
        self.keywords=['True',"False","None","await","else","import","pass","raise","return","try","while","with","yield","or","not","nonlocal",
        "lambda","is","in","except","finally","for","from","global","if","elif","del","def","continue","class","break","and","as","assert","async"]
        self.operators=['+','-','*','/','>','<','=','%','!','^']
        self.digits=['0','1','2','3','4','5','6','7','8','9']
        self.symbol=['@','!',"#",'$','%',".",'"',"'",".","`","&",'=','+','-','*','/',':','}','{','[',']','(',')','%','<','~',',',';','>','!','^',"|","?"]

    def isDelimiter(self,ch):
        return(ch in self.delimiter)

    def isOperator(self,ch):
        return(ch in self.operators)

    def isValidIdentifier(self,str):
        if(str[0] in self.digits or str[0] in self.delimiter or str[0] in self.symbol):
            return False
        for i in str:
            if(i in self.delimiter or i in self.symbol):
                return False
        return True

    def isKeyWord(self,str):
        return(str in self.keywords)

    def isInteger(self,str):
        if(len(str)==0):
            return False
        count=0
        for i in str:
            if(i not in self.digits  or  (i=="-" and count>0)):
                return False
            count+=1
        return True

    def isRealNumber(self,str):
        if(len(str)==int(0.0)):
            return False
        real=False
        count=0
        for i in str:
            if(i not in self.digits and i!='.'  or  (i=="-" and count>0)):
                return False
            count+=1
            if(i=='.'):
                real=True;
        return real

    def subString(self,s,l,r):
        str=""
        for i in range(l,r+1):
            str+=s[i]
        return str

    def parse(self,s):
        l=0;r=0;length=len(s)
        while(r<length and l<=r):
            if(s[r] in self.symbol or s[r]=="_"):
                self.analyser["specialCharacter"].append(s[r])
            if(self.isDelimiter(s[r])==False):
                r+=1
            if(self.isDelimiter(s[r])==True and r==l):
                if(self.isOperator(s[r])==True):
                    self.analyser["operator"].append(s[r])
                r+=1
                l=r
            elif(self.isDelimiter(s[r])==True and r!=l or (r==length and l!=r)):
                str=self.subString(s,l,r-1)
                if(self.isKeyWord(str)==True):
                    self.analyser["keyword"].append(str)
                elif(self.isInteger(str)==True):
                    self.analyser["integer"].append(str)
                elif(self.isRealNumber(str)==True):
                    self.analyser["realNumber"].append(str)
                elif(self.isValidIdentifier(str)==True and self.isDelimiter(s[r-1])==False):
                    self.analyser["identifier"].append(str)
                l=r

    def __str__(self):
        print("KEYWORDS:",','.join([i for i in self.analyser["keyword"]]),"\n")
        print("IDENTIFIERS:",','.join([i for i in self.analyser["identifier"]]),"\n")
        print("CONSTANTS")
        print("INTEGERS:",','.join([i for i in self.analyser["integer"]]))
        print("REALNUMBERS:",','.join([i for i in self.analyser["realNumber"]]),"\n")
        print("OPERATORS:",','.join([i for i in self.analyser["operator"]]),"\n")
        print("SPECIALCHARACTERS:",','.join([i for i in self.analyser["specialCharacter"]]),"\n")
        print("                               @######$COUNTS$######@")
        print("KEYWORDS.......IDENTIFIERS...........CONSTANTS............OPERATORS......SPECIAL CHARACTERS")
        print("                                 INTEGERS...REALNUMBERS")
        return (str(len(self.analyser["keyword"]))+"               "+str(len(self.analyser["identifier"]))+"                "
        +str(len(self.analyser["integer"]))+"       "+str(len(self.analyser["realNumber"]))+"              "+str(len(self.analyser["operator"]))
        +"               "+str(len(self.analyser["specialCharacter"])))
if __name__ == "__main__":
    s=""
    file=open('code.txt','r')
    # same code as input
    for each in file:
        if(each !='\n'):
            s=s+each[:len(each)-1]+" "
    Analyser=LexicalAnalyser()
    Analyser.parse(s)
    print(Analyser)
