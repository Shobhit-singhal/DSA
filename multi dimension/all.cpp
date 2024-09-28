#include<iostream>
#include<vector>
using namespace std;
bool isPresent(int mat[][4],int row,int col,int target){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]==target)
            return 1;
        }
    }
    return 0;
}

void calcRowSum(int mat[][4],int row,int col){
    int largest=-1;
    int maxi=-1;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<col;j++){
            sum+=mat[i][j];
        }
            if(maxi<sum){
                maxi=sum;
                largest=i;
            }
    }
    cout<<"Largest sum ROw: "<<largest+1<<"with"<<maxi<<endl;
}
void print(int mat[][4],int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
}



// void rotate(vector<vector<int>>& matrix) {
//     int row=matrix.size();
//     int col=matrix[0].size();
//     for(int i=0;i<row;i++){
//         for(int j=i+1;j<col;j++){
//             cout<<matrix[i][j]<<" "<<matrix[j][i]<<endl;
//             swap(matrix[i][j],matrix[j][i]);
//         }
//     }
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             cout<<matrix[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        int strtRow=0,endRow=row-1;
        int strtCol=0,endCol=col-1;
        int total=row*col,count=0;
        //swap strtrow strtcol to strtrow endcol
        //swap strtrow strtcol to endrow endcol
        //swap strtrow strtcol to endrow endstart
        //strtRow++,startcol++,endrow--,endcol--

        while(count<=total){
            while(strtRow<endRow){
                swap(matrix[strtRow][strtCol],matrix[strtRow][endCol]);
                swap(matrix[strtRow][strtCol],matrix[endRow][endCol]);
                swap(matrix[strtRow][strtCol],matrix[endRow][strtCol]);
                for(int i=0;i<row;i++){
                    for(int j=0;j<col;j++){
                    cout<<matrix[i][j]<<" ";
                    }
                cout<<endl;
                }
                cout<<endl;
                count+=4;
                strtCol++,endCol--;
            }
            strtCol=0,endCol=0;
            strtRow++,endRow--;
        }
        
    }

int main(){
    int mat[3][4];
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<4;j++){
    //         cin>>mat[i][j];
    //     }
    // }
    // print(mat,3,4);
    

    // int target;
    // cin>>target;
    // if(isPresent(mat,3,4,target)){
    //     cout<<"Present"<<endl;
    // }else
    //     cout<<"Not present";
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};
    rotate(v);
    // calcRowSum(mat,3,4);
}