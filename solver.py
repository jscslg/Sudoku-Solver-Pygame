def check(s,x,y,z):
    for i in range(0,9):
        if i!=y and s[x][i]==z: 
            return False
    for i in range(0,9):
        if i!=x and s[i][y]==z: 
            return False
    for i in range(x-x%3,x+3-x%3):
        for j in range(y-y%3,y+3-y%3):
            if i!=x and j!=y and s[i][j]==z: 
                return False
    return True

def solve(s,x,y):
    if x==8 and y==9:
        return True
    if y==9:
        x+=1
        y=0
    if s[x][y]>0: 
        return solve(s,x,y+1)
    for i in range(1,10):
        if check(s,x,y,i):
            s[x][y]=i
            if solve(s,x,y+1): 
                return True
            s[x][y]=0
    return False

def display(s):
    for i in range(0,9):
        for j in range(0,9):
            print(s[i][j],end=" ")
        print("\n",end="")

def main():
    board = [
        [3, 0, 6, 5, 0, 8, 4, 0, 0],
        [5, 2, 0, 1, 3, 0, 0, 0, 0],
        [0, 8, 7, 0, 0, 0, 5, 3, 1],
        [0, 0, 3, 0, 1, 0, 0, 8, 0],
        [9, 0, 0, 8, 6, 3, 0, 0, 5],
        [0, 5, 0, 0, 9, 0, 6, 0, 0],
        [1, 3, 0, 0, 0, 0, 2, 5, 0],
        [0, 0, 0, 0, 0, 0, 0, 7, 4],
        [7, 0, 5, 2, 0, 6, 3, 0, 0]
    ]
    if solve(board,0,0):
        display(board)
    else:
        print("No Solution")

main()