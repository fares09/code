#for some reason it consider Xwins inside a function a new variable :/ .
#YOUR MUST ENTER X OR O IN THE CORRECT POSITION


Board=[["*","*","*"]
      ,["*","*","*"],
       ["*","*","*"]]

playerXinputList=[]
playerOinputList=[]


def ShowBoard():
    for row in range(len(Board)):
        for colum in range(len(Board[row])):
            print(Board[row][colum],end=' ')
        
        print("\n",end="")

        

def Check_Up_down(InputType,coordinate):

    #hold the colum and move the row
    WiningTestList=[]
    Rowcounter=0
    while(Rowcounter<3):
         
         if(Board[Rowcounter][coordinate[1]]==InputType):
             WiningTestList.append(InputType)
         Rowcounter+=1
    
    if(len(WiningTestList)==3):
        return True
    else:
        return False


def Check_left_right(InputType,coordinate):
    #hold the row and change the colum
    WiningTestList=[]
    Columcounter=0
    while(Columcounter<3):
         if(Board[coordinate[0]][Columcounter]==InputType):
             WiningTestList.append(InputType)
         Columcounter+=1
    if(len(WiningTestList)==3):
        return True
    else:
        return False


def Check_left_diagnal(InputType,coordinate):
    #check whether the position in a valid diagnal(middle diagnal) and test .
    if(coordinate[0]==coordinate[1]):
          WiningTestList=[]
          diagnalcounter=0
          while(diagnalcounter<3):
              if(Board[diagnalcounter][diagnalcounter]==InputType):
                  WiningTestList.append(InputType)
              diagnalcounter+=1

          if(len(WiningTestList)==3):
              return True
    else:
        return False


def Check_right_diagnal(InputType,coordinate):
    
    #check whether the position in a valid diagnal(middle diagnal) and test .
    #neglecting whether if the position is on the right middle diagnal.
    RowC=0
    ColumC=2
    WiningTestList=[]
    while(RowC<3):
        if(Board[RowC][ColumC]==InputType):
             WiningTestList.append(InputType)
        RowC+=1
        ColumC-=1

    if(len(WiningTestList)==3):
        return True
    else:
        return False

    


def Check_Wining_conditions(playerTypeInputList,InputType):
     for coordinate in playerTypeInputList:      
       if(Check_Up_down(InputType,coordinate) or Check_left_right(InputType,coordinate) or Check_left_diagnal(InputType,coordinate) or Check_right_diagnal(InputType,coordinate) ):
           return True
       else:
           return False

      
     
def Check_Draw ():
        DrawIndicator=0
        for R in range(len(Board)):
            for C in range(len(Board[R])):
                           if(Board[R][C]=="*"):
                              DrawIndicator+=1
        if(DrawIndicator==0):
            print("Draw!!")
            return True
        else:
          
          return False

          
    
# The program starts here.....
ShowBoard() 
while(True):
    #taking input 1
    player1Input=input("enter x: ")
    player1Input="x"#To make input Case insensitive
    P1R=int(input("enter your row: "))
    P1C=int(input("enter your colum: "))
    
    #checks boundary
    if(P1R>=3 or P1C>=3 or P1R<0 or P1C<0):
        print("out of Board boundary!")
        P1R=int(input("enter your row: "))
        P1C=int(input("enter your colum: "))
        
     #check valid position   
    if(Board[P1R][P1C]!="*"):
        print("An occupied position!")
        P1R=int(input("enter your row: "))
        P1C=int(input("enter your colum: "))

        
    Board[P1R][P1C]=player1Input
    playerXinputList.append([P1R,P1C])
    ShowBoard()
    
    if(Check_Wining_conditions(playerXinputList,"x")):
        print("player 1 wins!!")
        break
    if(Check_Draw()):
        break

    # taking Input 2
    player2Input=input("enter o: ")
    player2Input="o"#to make input case insensitive
    P2R=int(input("enter your row: "))
    P2C=int(input("enter your colum: "))

    
      #checks boundary
    if(P2R>=3 or P2C>=3 or P1C<0 or P1R<0):
        print("out of Board boundary!")
        P2R=int(input("enter your row: "))
        P2C=int(input("enter your colum: "))

        
        
     #check valid position   
    if(Board[P2R][P2C]!="*"):
        print("An occupied position!")
        P2R=int(input("enter your row: "))
        P2C=int(input("enter your colum: "))

        

    Board[P2R][P2C]=player2Input
    playerOinputList.append([P2R,P2C])

    ShowBoard()
    
    if(Check_Wining_conditions(playerOinputList,"o")):
              print("player 2 wins!!")
              break
    if(Check_Draw()):
       break

 
    
    
                       
                       

   
