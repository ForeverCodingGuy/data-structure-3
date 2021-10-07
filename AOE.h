#include<iostream>
#include<stack>
using namespace std;
const int MAX_VERTEX = 20;
//定义边表
class ArcNode
{
public:
	int adjvex;
	int weight;
	ArcNode* next;
};
//定义顶点表
class VertexNode
{
public:
	char vertex;
	int in;
	ArcNode* firstEdge;
};
//定义邻接链表
class ALGraph
{
public:
	int vertexnum;
	int arcnum;
	VertexNode* adjlist;
	int* ve;
	int* vl;
	ALGraph(char* v, int n, int m);//构造函数
	~ALGraph();//析构函数
	void inputEdges();//输入顶点关系即时间关系，以及路径长度即活动时间
	bool setEdge(int vi, int vj, int weight);//修改或加入顶点关系及时间，同时返回是否成功
	bool TopoLogicalSort(int resylt[],int &count);//拓扑排序算法
	bool GriticalPath();//关键路径
};
int main()
{
	char vertex[MAX_VERTEX];
	int num, edge;
	cout << "请输入顶点数和边的个数：" << endl;
	cin >> num >> edge;
	for (int i = 0; i < num; i++)
	{
		vertex[i] = i + '0';
	}
	ALGraph graph(vertex, num, edge);
	graph.inputEdges();
	if (!graph.GriticalPath())
	{
		cout << "该工程有回路，不能求出关键路径" << endl;
	}
}
