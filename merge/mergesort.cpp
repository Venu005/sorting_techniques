#include <iostream>
#include <vector>

void Merge(std::vector <int>& A,int l,int mid,int h){
    int i = l;
    int j = mid+1;
    int k = l;
    std::vector <int> B(h+1);
    while(i<=mid && j<=h){
        if(A[i]<A[j]){
            B[k++] = A[i++];
        }else{
            B[k++]= A[j++];
        }
    }
        for(;i<=mid;i++){
            B[k++] = A[i];
        }
        for(;j<=h;j++){
            B[k++] = A[j];
        }
        for(int i = l;i<=h;i++){
            A[i] = B[i];
        }

    

}

void Remerge(std::vector<int>& A,int l,int h){
    int mid;
    if(l<h){
        mid = (l+h)/2;
        Remerge(A,l,mid);
        Remerge(A,mid+1,h);
        Merge(A,l,mid,h);
    }
}

void print(std::vector <int> A){
    for(auto &elem : A){
        std::cout << elem << " ";
    }

}
int main(){
    std::vector <int> A;
    int n;
    std::cin >> n;
    for(int i = 0;i<n;i++){
        int x;
        std::cin >> x;
        A.push_back(x);
    }
    Remerge(A,0,n-1);
    print(A);
    return  0;
}