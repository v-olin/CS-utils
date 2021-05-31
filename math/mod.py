import sys

class Statement:
    def __init__(self, b, p, m):
        self.base = b
        self.power = p
        self.modulo = m
        self.twoPowers = []

    def DeducePowers(self):
        cp = self.power
        while cp != 0:
            hp = self.GetMaxTwoPower(cp)
            cp -= hp
            self.twoPowers.append(hp)

    def GetMaxTwoPower(self, p):
        cp = 1
        while True:
            if cp * 2 <= p:
                cp *= 2
            else:
                break
        return cp

def PrintSolution(s):
    powerStr = '{}^{}'.format(s.base, s.twoPowers[0])
    for i in range(1, len(s.twoPowers)):
        powerStr += ' * {}^{}'.format(s.base, s.twoPowers[i])
    print(powerStr)
    cp = 1
    while cp <= s.twoPowers[0]:
        if cp > 2:
            tempCP = cp // 2
            expansion = ""
            temp = (s.base**tempCP) % s.modulo
            if temp > 10:
                fst = (temp // 10) * 10
                snd = temp % 10
                lastTerm = '({}+{})'.format(fst, snd)
                expansion = '{} + {} + {}'.format(fst**2, 2*(fst * snd), snd**2)
                step = '{}^{} = {}^{} = {} = {}'.format(s.base, cp, lastTerm, 2, expansion, (temp**2) % s.modulo)
            else:
                lastTerm = ((s.base**tempCP) % s.modulo)
                step = '{}^{} = {}^{} = {}'.format(s.base, cp, lastTerm, 2, (temp**2) % s.modulo)
            print(step)
        else:
            print('{}^{} = {}'.format(s.base, cp, s.base**cp))
        cp *= 2
    finalAdd = '{}^{} = {}'.format(s.base, s.power, (s.base**s.twoPowers[0]) % s.modulo)
    terms = [(s.base**s.twoPowers[0]) % s.modulo]
    for i in range(1, len(s.twoPowers)):
        finalAdd += ' * {}'.format((s.base**s.twoPowers[i]) % s.modulo)
        terms.append((s.base**s.twoPowers[i]) % s.modulo)
    print(finalAdd)
    print('{}^{} = {} (mod {})'.format(s.base, s.power, listProd(terms) % s.modulo, s.modulo))

def listProd(myList):
    result = 1
    for x in myList:
         result = result * x 
    return result

def ArgToList(str):
    n = len(str)
    a = str.split(',')
    return [int(i) for i in a]

def DeduceStatement(list):
    base = list[0]
    power = list[1]
    modulo = list[2]
    if base > modulo:
        print('{} = ({} * {} + {})'.format(base, modulo, (base // modulo), base % modulo))
        base = base % modulo
    return [base, power, modulo]

args = DeduceStatement(ArgToList(sys.argv[1]))
state = Statement(args[0], args[1], args[2])
state.DeducePowers()
PrintSolution(state)