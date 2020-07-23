#include <iostream>
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

bool check(int s[9][9],int x,int y,int z){
    for(int i=0;i<9;i++){
        if(i!=y&&s[x][i]==z) return false;
    }
    for(int i=0;i<9;i++){
        if(i!=x&&s[i][y]==z) return false;
    }
    for(int i=(x-x%3);i<(x+3-x%3);i++){
        for(int j=(y-y%3);j<(y+3-y%3);j++){
            if(i!=x&&j!=y&&s[i][j]==z) return false;
        }
    }
    return true;
}
bool solve(int s[9][9],int x,int y){
    if(x==8&&y==9) return true;
    if(y==9){
        x++;
        y=0;
    }
    if(s[x][y]>0) return solve(s,x,y+1);
    for(int i=1;i<=9;i++){
        if(check(s,x,y,i)){
            s[x][y]=i;
            if(solve(s,x,y+1)) return true;
            s[x][y]=0;
        }
    }
    return false;
}
void print(int s[9][9]){
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) cout<<s[i][j]<<" ";
        cout<<endl;
    }
}

int main() {
    fast;
    int s[9][9]= 
        {{3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 1, 3, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 5, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {7, 0, 5, 2, 0, 6, 3, 0, 0}};

    //for(int i=0;i<9;i++) for(int j=0;j<9;j++) cin>>s[i][j];

    if(solve(s,0,0)){
        print(s);
    }
    else cout<<"No Solution";
    
	return 0;
}