/*
Ϊ���ҵ��Լ�����Ĺ�����ţţ�ռ���ÿ�ֹ������ѶȺͱ��ꡣţţѡ�����ı�׼�����ѶȲ�������������ֵ������£�ţţѡ�񱨳���ߵĹ�������ţţѡ�����Լ��Ĺ�����ţţ��С���������ţţ��æѡ������ţţ��Ȼʹ���Լ��ı�׼������С����ǡ�ţţ��С���̫���ˣ�������ֻ�ð�������񽻸����㡣
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а����������������ֱ��ʾ����������N(N<=100000)��С��������M(M<=100000)��
��������N��ÿ�а����������������ֱ��ʾ��������Ѷ�Di(Di<=1000000000)�ͱ���Pi(Pi<=1000000000)��
��������һ�а���M�����������ֱ��ʾM��С��������ֵAi(Ai<=1000000000)��
��֤������������ı�����ͬ��


�������:
����ÿ��С��飬�ڵ�����һ�����һ����������ʾ���ܵõ�����߱��ꡣһ���������Ա������ѡ��

��������1:
3 3
1 100
10 1000
1000000000 1001
9 10 1000000000

�������1:
100
1000
1001
*/
//�Ѷ�����ʱ�临�Ӷ�

//��һ�ֽⷨ����������ʱ
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int N, M;
//	cin >> N >> M;
//	vector<int> Di(N), Pi(N);
//	vector<int> Ai(M), Money(M);
//	int i, j;
//	for (i = 0; i < N; ++i) {
//		cin >> Di[i] >> Pi[i];
//	}
//	for (j = 0; j < M; ++j) {
//		cin >> Ai[j];
//	}
//
//	for (j = 0; j < M; ++j) {
//		for (i = 0; i < N; ++i) {
//			if (Ai[j] >= Di[i]) {
//				if (Money[j] < Pi[i])
//					Money[j] = Pi[i];
//				//Money[j] < Pi[i] ? Pi[i] : Money[j];
//			}
//		}
//	}
//	for (j = 0; j < M; ++j) {
//		cout << Money[j] << endl;
//	}
//
//}
////�ڶ��ֽⷨ��������
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main() {
//	int N, M;
//	cin >> N >> M;
//	vector<pair<int, int>> job(N),guy(M);
//	vector<int> Money(M);
//	int i, j;
//	int d, p;
//	for (i = 0; i < N; ++i) {
//		cin >> d >> p;
//		job[i].first = d;
//		job[i].second=p;
//	}
//	for (j = 0; j < M; ++j) {
//		cin>>guy[j].first;
//		guy[j].second = j;//������¼�����ԭ����λ��
//	}	
//	sort(job.begin(), job.end());
//	sort(guy.begin(), guy.end());
//
//	for (i = 1; i < N; ++i) {
//		job[i].second = max(job[i].second, job[i - 1].second);
//	}
//
//	for (j = 0,i=0; j < M; ) {
//		if (i >= N) {
//			Money[guy[j++].second] = job[N - 1].second;
//		}
//		else if(guy[j].first >= job[i].first) {
//			//Money[j] = job[i].second;
//			i++;
//		}
//		else {
//			if(i>0)
//				Money[guy[j].second] = job[i - 1].second;
//			else Money[guy[j].second] = 0;
//			j++;
//		}
//	}
//	for (j = 0; j < M; ++j) {
//		cout << Money[j] << endl;
//	}
//}

/*
���ӣ�https://www.nowcoder.com/questionTerminal/bac5a2372e204b2ab04cc437db76dc4f?orderByHotValue=0&page=1&onlyReference=false
��Դ��ţ����

ţţ��ǰ����ʦ����õ���һ������������(x, y), ţţ�������Ǿ����Ƕ����ˡ�
����ţţ�ǵ���ʦ���߹���x��y��������n, ����x����y���������ڵ���k��
ţţϣ�����ܰ�������һ���ж��ٸ����ܵ����ԡ�

��������:
�����������������n,k(1 <= n <= 10^5, 0 <= k <= n - 1)��

�������:
����ÿ����������, ���һ����������ʾ���ܵ�����������
ʾ��1
����
5 2
���
7
˵��
����������������(2,3),(2,4),(2,5),(3,4),(3,5),(4,5),(5,3)
*/
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int main() {
//	int n, k;
//	cin >> n >> k;
//	long long count=0, each_count=0;
//	int y = max(1,k);
//	for (; y <= n; ++y) {
//		each_count = (y - k)*(n / y);//����n/y��ѭ�����еĸ���
//		if (n%y >= k) {//�������ղ���һ��ѭ���ڣ�ʣ�µ���������K�ĸ���
//			if (k)
//				each_count += n%y - k + 1;//���k������0
//			else
//				each_count += n%y;//���k����0������ļ��㷽ʽ�Ͷ�����һ��
//		}
//		count += each_count;
//	}
//	cout << count << endl;
//}

/*
���ӣ�https://www.nowcoder.com/questionTerminal/51dcb4eef6004f6f8f44d927463ad5e8?orderByHotValue=0&page=1&onlyReference=false
��Դ��ţ����

СQ�õ�һ�����������: 1, 12, 123,...12345678910,1234567891011...��
����СQ�����ܷ�3����������ʺܸ���Ȥ��
СQ����ϣ�����ܰ�������һ�´����еĵ�l������r��(�����˵�)�ж��ٸ������Ա�3������

��������:
���������������l��r(1 <= l <= r <= 1e9), ��ʾҪ�����������ˡ�


�������:
���һ������, ��ʾ�������ܱ�3���������ָ�����
*/
//��ѭ���������ã��������ַ�ʽ����
//#include<iostream>
//
//using namespace std;
//
//int main() {
//	long long l, r;
//	cin >> l >> r;
//	long long count = 0, i = 0;
//	int t = 0;//t��ʾ����
//	for (i = 1; i <= r; ++i) {
//		t += i % 3;
//		if (t >= 3)
//			t %= 3;
//		if (i >= l&&t == 0) {
//			count++;
//		}
//	}
//	cout << count << endl;
//}
//�ڶ��ַ�ʽ�����ֹ��ɣ�1~1...r  ������  ������ ������... ��ȥ��ĸ���
#include<iostream>
#define getNo(x) ((x+2)/3)
using namespace std;

int main() {
	long long l, r;
	cin >> l >> r;
	long long count = 0;
	cout << r - l + 1 - (getNo(r) - getNo(l - 1)) << endl;
}