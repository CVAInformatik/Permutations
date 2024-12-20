
import math
import random
al = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]


def myPerm( N1, ain):  
	   return my_Perm(N1, ain.copy() )
	   
def my_Perm(N2, ain ):
		n1 = N2
		res = []
		for n in range( 0, len(ain) ):
			res.insert(n1 % (n+1), ain.pop())
			n1 = n1 // (n+1)
		return res

def test (A):
		for n3 in range ( A, (A+100)):
			print ( myPerm( n3, al))	

# make a deck of cars
def makedeck():
	res = []
	for colour in [ "Hearts", "Spades", "Diamonds", "Clubs" ]:
		for rank  in ["Ace", "2", "3", "4","5", "6","7","8", "9", "10", "Jack", "Queen", "King" ]:
			res.insert(0, rank + " " + colour )
	return res

deck = makedeck()

# shuffle  a new deck of cards
def shuffle():
		return   myPerm( random.randrange(0,math.factorial(54)), makedeck())	

# re-shuffle a deck of cards
def shuffle1( adeck):
		return   myPerm( random.randrange(0,math.factorial(54)), adeck)	

#deal four hands of 13 cards
def dealHands (adeck):
			res = []
			res.insert(0,adeck[0:13])	
			res.insert(0,adeck[13:26])	
			res.insert(0,adeck[26:39])	
			res.insert(0,adeck[39:52])
			return res	

#  print the four hands
def printHands( hands):
	print( hands[0])
	print( hands[1])
	print( hands[2])
	print( hands[3])
		
#print ( 	myPerm(249446731344869416764, al)	)
#al = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]	
#print ( 	my_Perm(24944673134486937429416764, al)	)
#al = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
#print ( 	my_Perm(0, al)	)


def find0(aPermutation) :
    for n in range( 0, len(aPermutation) ):
      if( aPermutation[n] == 0) :
         return n
    return 0 

	  
def  remove0( aPermutation) :
    res = [];
    for n in range( 0, len(aPermutation)):
      if( aPermutation[n] != 0): res.append(aPermutation[n]-1)
    return res
		
# returns the permutation index when given a permuation of [0,1,2,3,..n-1];
# findN( permuation( N, [0,1,2,3,...n-1)); 
# should return  N 

def findN(aPermutation) :
    return _findN(aPermutation.copy(), 0)
			
def _findN(aPerm, ll) :
    alen = len(aPerm);
    match alen :
      case 0: 
         return 0;	  		
      case 1:	
         return 0;
      case 2:	
         if( (aPerm[0]) == 0):
            return ll
         else:
            return ll+1	  				
      case _:	
         pos = find0(aPerm)
         fac_alen_minus_1 = math.factorial(alen-1)
         aPerm_ = remove0(aPerm.copy())
         return _findN( aPerm_, ll + ( pos * fac_alen_minus_1))

def Pos( N, aPerm):
    for n in range( 0, len(aPerm) ):
       if( aPerm[n] == N):
            return n
    return -1 
    
def Inverse( aPerm ):
    res = [];
    for n in range( 0,  len(aPerm)):
         res.append( Pos(n, aPerm)) 	  
    return res
    