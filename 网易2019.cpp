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
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> Di(N), Pi(N);
	vector<int> Ai(M), Money(M);
	int i, j;
	for (i = 0; i < N; ++i) {
		cin >> Di[i] >> Pi[i];
	}
	for (j = 0; j < M; ++j) {
		cin >> Ai[j];
	}

	for (j = 0; j < M; ++j) {
		for (i = 0; i < N; ++i) {
			if (Ai[j] >= Di[i]) {
				if (Money[j] < Pi[i])
					Money[j] = Pi[i];
				//Money[j] < Pi[i] ? Pi[i] : Money[j];
			}
		}
	}
	for (j = 0; j < M; ++j) {
		cout << Money[j] << endl;
	}

}
////�ڶ��ֽⷨ��������
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> job(n),guy(m);
	vector<int> money(m);
	int i, j;
	int d, p;
	for (i = 0; i < n; ++i) {
		cin >> d >> p;
		job[i].first = d;
		job[i].second=p;
	}
	for (j = 0; j < m; ++j) {
		cin>>guy[j].first;
		guy[j].second = j;//������¼�����ԭ����λ��
	}	
	sort(job.begin(), job.end());
	sort(guy.begin(), guy.end());

	for (i = 1; i < n; ++i) {
		job[i].second = max(job[i].second, job[i - 1].second);
	}

	for (j = 0,i=0; j < m; ) {
		if (i >= n) {
			money[guy[j++].second] = job[n - 1].second;
		}
		else if(guy[j].first >= job[i].first) {
			//money[j] = job[i].second;
			i++;
		}
		else {
			if(i>0)
				money[guy[j].second] = job[i - 1].second;
			else money[guy[j].second] = 0;
			j++;
		}
	}
	for (j = 0; j < m; ++j) {
		cout << money[j] << endl;
	}
}

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
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	long long count=0, each_count=0;
	int y = max(1,k);
	for (; y <= n; ++y) {
		each_count = (y - k)*(n / y);//����n/y��ѭ�����еĸ���
		if (n%y >= k) {//�������ղ���һ��ѭ���ڣ�ʣ�µ���������K�ĸ���
			if (k)
				each_count += n%y - k + 1;//���k������0
			else
				each_count += n%y;//���k����0������ļ��㷽ʽ�Ͷ�����һ��
		}
		count += each_count;
	}
	cout << count << endl;
}

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
//���l��r���ܴ�1s��ִ�в��꣬��ѭ���������ã��������ַ�ʽ����
#include<iostream>

using namespace std;

int main() {
	long long l, r;
	cin >> l >> r;
	long long count = 0, i = 0;
	int t = 0;//t��ʾ����
	for (i = 1; i <= r; ++i) {
		t += i % 3;
		if (t >= 3)
			t %= 3;
		if (i >= l&&t == 0) {
			count++;
		}
	}
	cout << count << endl;
}
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

/*
���ӣ�https://www.nowcoder.com/questionTerminal/bf877f837467488692be703735db84e6?orderByHotValue=0&page=1&onlyReference=false
��Դ��ţ����

ţţ׼���μ�ѧУ��֯�Ĵ���, ����ǰţţ׼����������װ��һЩ��ʳ, ţţ�ı�������Ϊw��
ţţ����һ����n����ʳ, ��i����ʳ���Ϊv[i]��
ţţ��֪������������������������������,��һ���ж�������ʳ�ŷ�(�����Ϊ0Ҳ��һ�ַŷ�)��

��������:
�����������
��һ��Ϊ����������n��w(1 <= n <= 30, 1 <= w <= 2 * 10^9),��ʾ��ʳ�������ͱ�����������
�ڶ���n��������v[i](0 <= v[i] <= 10^9),��ʾÿ����ʳ�������


�������:
���һ��������, ��ʾţţһ���ж�������ʳ�ŷ���
ʾ��1
����
3 10
1 2 4
���
8
˵��
������ʳ�����С��10,����ÿ����ʳ�з���Ͳ��������������һ����2*2*2 = 8�������
*/
//����������������ķ��������Ϸ�֧�޽磬�����ǰ�����sum���������ݻ�w����return����Ȼ�Ļ����Ͳ��÷źͲ������ַ�ʽ����������
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

static ll cnt = 0;//��std����һ��count����
void dfs(vector<ll>v,ll sum, ll w,int cur, int n) {
	
	if (sum <= w&&cur == n)cnt++;
	if (cur >= n||sum>w) return;//��֧�޽�
	

	dfs(v, sum, w, cur + 1, n);
	dfs(v, sum + v[cur], w, cur + 1, n);
}
void my_print() {
	cout << fixed;//��ֹ����ÿ�ѧ��������ʾ
	cout.precision(0);
	cout << cnt << endl;
}
int main() {
	ll w, sum=0;
	int n;
	cin >> n >> w;
	vector<ll> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	if (sum <= w) {
		cnt= pow(2, n);
		my_print();
		return 0;
	}
	int cur = 0;
	sum = 0;
	dfs(v, sum, w, cur, n);
	my_print();
}
/*
���ӣ�https://www.nowcoder.com/questionTerminal/9173e83d1774462f81255a26feafd7c6?orderByHotValue=0
��Դ��ţ����

ţţ����˯��ͷ�����������˺ܶ����ӣ�ֻ�����������ʱ�����Ż��ѹ������Ҿ������𴲡���������������ҪX���ӵ�����ң��Ͽ�ʱ��Ϊ�����AʱB�֣��������������ʲôʱ����
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а���һ������������ʾ���ӵ�����N(N<=100)��
��������N��ÿ�а���������������ʾ������������ʱ��ΪHi(0<=A<24)ʱMi(0<=B<60)�֡�
��������һ�а���һ����������ʾ������������ҪX(0<=X<=100)���ӵ�����ҡ�
��������һ�а���������������ʾ�Ͽ�ʱ��ΪA(0<=A<24)ʱB(0<=B<60)�֡�
���ݱ�֤������һ�����ӿ�����ţţ��ʱ������ҡ�


�������:
�������������ʾţţ������ʱ�䡣
ʾ��1
����
3
5 0
6 0
7 0
59
6 59
���
6 0
*/
//���Ǻ�һ���˼·�������ʱ�䶼ת��Ϊ����
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	int N,H,M;
	cin >> N;
	vector<pair<int, int>> clock_t(N);
	int i;
	for (i = 0; i < N; ++i) {
		cin >> clock_t[i].first >> clock_t[i].second;
	}
	int X;
	cin >> X;
	pair<int, int> x_t;
	x_t.first = X / 60;
	x_t.second = X % 60;
	pair<int, int> class_t;
	cin >> class_t.first >> class_t.second;
	sort(clock_t.begin(), clock_t.end());

	for (i = 0; i < N; ++i) {
		if (clock_t[i].first + x_t.first+(clock_t[i].second + x_t.second)/60 <= class_t.first) {
			if ((clock_t[i].first + x_t.first + (clock_t[i].second + x_t.second) / 60 == class_t.first)&&(clock_t[i].second + x_t.second)%60 > class_t.second) {
				break;
			}
			H = clock_t[i].first;
			M = clock_t[i].second;
		}		
		else break;
	}
	cout << H << " " << M << endl;
}

/*
���ӣ�https://www.nowcoder.com/questionTerminal/3a3577b9d3294fb7845b96a9cd2e099c?orderByHotValue=0&page=1&onlyReference=false
��Դ��ţ����

СQ���ڸ�һ������Ϊn�ĵ�·���·�ư��÷�����
Ϊ�����������,СQ�ѵ�·��Ϊn������,��Ҫ�����ĵط���'.'��ʾ, ����Ҫ�������ϰ��������'X'��ʾ��
СQ����Ҫ�ڵ�·������һЩ·��, ���ڰ�����posλ�õ�·��, ��յ·�ƿ�������pos - 1, pos, pos + 1������λ�á�
СQϣ���ܰ��þ����ٵ�·����������'.'����, ϣ�����ܰ�������һ��������Ҫ����յ·�ơ�

��������:
����ĵ�һ�а���һ��������t(1 <= t <= 1000), ��ʾ����������
������ÿ����һ����������, ��һ��һ��������n(1 <= n <= 1000),��ʾ��·�ĳ��ȡ�
�ڶ���һ���ַ���s��ʾ��·�Ĺ���,ֻ����'.'��'X'��


�������:
����ÿ����������, ���һ����������ʾ������Ҫ����յ·�ơ�
ʾ��1
����
2
3
.X.
11
...XX....XX
���
1
3
*/
//˼·����ÿ����һ�飬�����һ����X����������һ���������.�������������һ������·�ƣ������Խ��Ļ��� ���˼·������������뵽�ͺܼ���
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	int t;
	int n,i=0,len=0;
	string s;
	int cnt=0;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> s;
		vector<int>dp(n);
		i = 0;
		cnt = 0;
		while (i < n) {
			if (s[i] == 'X') {
				dp[i++]=0;
				continue;
			}
			else {
				if (i + 3 <= n)
					dp[i + 1] = 1;
				else dp[i] = 1;
				i += 3;
			}
		}
		for (i = 0; i < n; ++i) {
			if (dp[i] == 1)cnt++;
		}
		cout << cnt << endl;
	}
}

/*
��·��ţţ

ţţȥ�Ġ���ʦ�Ҳ��Σ����ŵ�ʱ�����򱱷���������������·�ˡ���Ȼ��������һ�ŵ�ͼ����������Ҫ֪���Լ������ĸ���������������
��������:
ÿ���������һ������������
ÿ�����������ĵ�һ�а���һ������������ʾת����Ĵ���N(N<=1000)��
��������һ�а���һ������ΪN���ַ�������L��R��ɣ�L��ʾ����ת��R��ʾ����ת��

�������:
���ţţ�������ķ���N��ʾ����S��ʾ�ϣ�E��ʾ����W��ʾ����
ʾ��1
����
3
LRR
���
E
*/
#include<iostream>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	int i = 0,dir=0;
	while (i < N) {
		switch (s[i]) {
		case 'L': {
			dir += 1;
			break;
		}
		case 'R': {
			dir -= 1;
			break;
		}
		}
		if (dir >= 4)dir %= 4;
		if (dir < 0)dir += 4;
		++i;
	}
	switch (dir) {
	case 0:cout << 'N' << endl; break;
	case 1:cout << 'W' << endl; break;
	case 2:cout << 'S' << endl; break;
	case 3:cout << 'E' << endl; break;
	}
}
/*
�����ص���û��˼·��������
*/