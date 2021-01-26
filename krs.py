import sys

class Condition:
    def __init__(self, r, m):
        self.remainder = r
        self.modulo = m
        self.b = 1
        self.bigN = 1

class Statement:
    def __init__(self):
        self.cList = []

    def FillCList(self, list):
        condList = self.GetConditionList(list)
        condListWBigNs = self.SetBigNs(condList)
        self.cList = self.SetBs(condListWBigNs)

    def GetConditionList(self, list):
        internalList = []
        for i in range(0, len(list), 2):
            c = Condition(list[i], list[i+1])
            internalList.append(c)
        return internalList

    def SetBigNs(self, list):
        currentN = 1
        originalList = list
        tempList = []
        for i in range(0, len(originalList)):
            for k in range(0, len(originalList)):
                tempList.append(originalList[k])
            tempList.pop(i)
            for j in range(0, len(tempList)):
                currentN = currentN * tempList[j].modulo
            originalList[i].bigN = currentN
            currentN = 1
            tempList = []
        return originalList

    def SetBs(self, list):
        for i in range(0, len(list)):
            tempb = 1
            tempN = list[i].bigN
            tempm = list[i].modulo
            while (tempb * tempN) % tempm != 1:
                tempb += 1
            list[i].b = tempb
        return list

def ArgToList(str):
    n = len(str)
    a = str[1:n-1]
    a = a.split(',')
    return [int(i) for i in a]

def PrintSolution(statement):
    print("States of conditions:")
    mod = 1
    tot = 0
    add = ""
    for i in range(0, len(statement.cList)):
        cc = statement.cList[i]
        str = 'a{}: {}\tN{}: {}\tb{}: {}'.format(i+1, cc.remainder, i+1, cc.bigN, i+1, cc.b)
        add += '{}*{}*{} + '.format(cc.remainder, cc.b, cc.bigN)
        mod = mod * cc.modulo
        tot += cc.remainder * cc.b * cc.bigN
        print(str)
    add = add[0:(len(add))-3]
    print("Enligt a*b*N:")
    modStr = '(mod {})'.format(mod)
    print(add)
    print('{} {} => x = {} {}'.format(tot, modStr, tot % mod, modStr))

task = Statement()
argList = ArgToList(sys.argv[1])
task.FillCList(argList)
PrintSolution(task)