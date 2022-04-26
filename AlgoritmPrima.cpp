#include <iostream>
 //������� ������ ���������� ������, ����� ������� ��������� � ���, ������� ��� (������� ��������� ��� M �� M ������� ��� ��������� ���� � ���� ��� �������, ������ ��� �������� ��������� ��� ���������� �� 3 �� 3 ����� 0
using std::cout;
using std::cin;
 
int a, b, u, v, ne = 1;
int visited[10] = {0}, min = 0, mincost=0, cost[10][10];
 
int main()
{
    int n = 0;
	int path[100] = {0}; //������ ��� ������
	int path_index = 0;
 
	//clrscr();
	cout << "Number of vertices"; //���-�� ������
    cin >> n;
 
    
	cout << "Adjacency matrix\n"; //������� ���������
 
 
 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> cost[i][j];
            if(cost[i][j] == 0)
                cost[i][j] = 999; //999 - ���� ����������� ����������, ���������� ��� ���������� � ���������
        }
    }
    
	visited[1] = 1;
	cout << "\n";
 
   
    
	while(ne < n){
        int min = 999;
        int i = 1;
        for(; i<=n; i++){                  
            for(int j=1; j<=n; j++){
                if(cost[i][j] < min){
                     if(visited[i] != 0)
                     {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                     }
                }
            }            
         }
           
 
        if(visited[u] == 0 || visited[v] == 0) {
            path[path_index] = b;
            path_index++;
            //cout<<"\n "<<ne++<<"  "<<a<<"  "<<b<<min; //
            ne++; // ���� ��� �������, ���� �� ��� ����
            mincost+= min;
            visited[b] = 1;
        }
            
		cost[a][b] = cost[b][a] = 999;
	}
 
	cout << "\n";
 
	cout << 1 << " --> ";
	for (int i=0; i<n-1; i++)
	{
	  cout << path[i];
	  if (i < n-2) cout <<" --> ";
	}
 
	cout << "\n Minimum cost  " << mincost;
}
