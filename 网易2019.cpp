/*
为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
保证不存在两项工作的报酬相同。


输出描述:
对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。

输入例子1:
3 3
1 100
10 1000
1000000000 1001
9 10 1000000000

输出例子1:
100
1000
1001
*/
//难度在于时间复杂度

//第一种解法，暴力法超时
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
////第二种解法，先排序
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
		guy[j].second = j;//排序后记录这个人原来的位置
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
链接：https://www.nowcoder.com/questionTerminal/bac5a2372e204b2ab04cc437db76dc4f?orderByHotValue=0&page=1&onlyReference=false
来源：牛客网

牛牛以前在老师那里得到了一个正整数数对(x, y), 牛牛忘记他们具体是多少了。
但是牛牛记得老师告诉过他x和y均不大于n, 并且x除以y的余数大于等于k。
牛牛希望你能帮他计算一共有多少个可能的数对。

输入描述:
输入包括两个正整数n,k(1 <= n <= 10^5, 0 <= k <= n - 1)。

输出描述:
对于每个测试用例, 输出一个正整数表示可能的数对数量。
示例1
输入
5 2
输出
7
说明
满足条件的数对有(2,3),(2,4),(2,5),(3,4),(3,5),(4,5),(5,3)
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
		each_count = (y - k)*(n / y);//计算n/y个循环节中的个数
		if (n%y >= k) {//计算最后凑不齐一个循环节，剩下的余数大于K的个数
			if (k)
				each_count += n%y - k + 1;//如果k不等于0
			else
				each_count += n%y;//如果k等于0，上面的计算方式就多算了一个
		}
		count += each_count;
	}
	cout << count << endl;
}

/*
链接：https://www.nowcoder.com/questionTerminal/51dcb4eef6004f6f8f44d927463ad5e8?orderByHotValue=0&page=1&onlyReference=false
来源：牛客网

小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。
并且小Q对于能否被3整除这个性质很感兴趣。
小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。

输入描述:
输入包括两个整数l和r(1 <= l <= r <= 1e9), 表示要求解的区间两端。


输出描述:
输出一个整数, 表示区间内能被3整除的数字个数。
*/
//如果l和r相差很大，1s内执行不完，连循环都不能用，所以这种方式不行
#include<iostream>

using namespace std;

int main() {
	long long l, r;
	cin >> l >> r;
	long long count = 0, i = 0;
	int t = 0;//t表示余数
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
//第二种方式，发现规律：1~1...r  否是是  否是是 否是是... 减去否的个数
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
链接：https://www.nowcoder.com/questionTerminal/bf877f837467488692be703735db84e6?orderByHotValue=0&page=1&onlyReference=false
来源：牛客网

牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容量为w。
牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。

输入描述:
输入包括两行
第一行为两个正整数n和w(1 <= n <= 30, 1 <= w <= 2 * 10^9),表示零食的数量和背包的容量。
第二行n个正整数v[i](0 <= v[i] <= 10^9),表示每袋零食的体积。


输出描述:
输出一个正整数, 表示牛牛一共有多少种零食放法。
示例1
输入
3 10
1 2 4
输出
8
说明
三种零食总体积小于10,于是每种零食有放入和不放入两种情况，一共有2*2*2 = 8种情况。
*/
//采用深度优先搜索的方法，加上分支限界，如果当前总体积sum超过背包容积w，就return；不然的话，就采用放和不放两种方式继续搜索。
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

static ll cnt = 0;//在std中有一个count函数
void dfs(vector<ll>v,ll sum, ll w,int cur, int n) {
	
	if (sum <= w&&cur == n)cnt++;
	if (cur >= n||sum>w) return;//分支限界
	

	dfs(v, sum, w, cur + 1, n);
	dfs(v, sum + v[cur], w, cur + 1, n);
}
void my_print() {
	cout << fixed;//防止输出用科学计数法表示
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
链接：https://www.nowcoder.com/questionTerminal/9173e83d1774462f81255a26feafd7c6?orderByHotValue=0
来源：牛客网

牛牛总是睡过头，所以他定了很多闹钟，只有在闹钟响的时候他才会醒过来并且决定起不起床。从他起床算起他需要X分钟到达教室，上课时间为当天的A时B分，请问他最晚可以什么时间起床
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示闹钟的数量N(N<=100)。
接下来的N行每行包含两个整数，表示这个闹钟响起的时间为Hi(0<=A<24)时Mi(0<=B<60)分。
接下来的一行包含一个整数，表示从起床算起他需要X(0<=X<=100)分钟到达教室。
接下来的一行包含两个整数，表示上课时间为A(0<=A<24)时B(0<=B<60)分。
数据保证至少有一个闹钟可以让牛牛及时到达教室。


输出描述:
输出两个整数表示牛牛最晚起床时间。
示例1
输入
3
5 0
6 0
7 0
59
6 59
输出
6 0
*/
//这是很一般的思路，不如把时间都转化为分钟
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
链接：https://www.nowcoder.com/questionTerminal/3a3577b9d3294fb7845b96a9cd2e099c?orderByHotValue=0&page=1&onlyReference=false
来源：牛客网

小Q正在给一条长度为n的道路设计路灯安置方案。
为了让问题更简单,小Q把道路视为n个方格,需要照亮的地方用'.'表示, 不需要照亮的障碍物格子用'X'表示。
小Q现在要在道路上设置一些路灯, 对于安置在pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。
小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需要多少盏路灯。

输入描述:
输入的第一行包含一个正整数t(1 <= t <= 1000), 表示测试用例数
接下来每两行一个测试数据, 第一行一个正整数n(1 <= n <= 1000),表示道路的长度。
第二行一个字符串s表示道路的构造,只包含'.'和'X'。


输出描述:
对于每个测试用例, 输出一个正整数表示最少需要多少盏路灯。
示例1
输入
2
3
.X.
11
...XX....XX
输出
1
3
*/
//思路就是每三个一组，如果第一个是X，就跳到下一个，如果是.，就在这个的下一个放置路灯（如果不越界的话） 这个思路。。。。如果想到就很简单了
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
迷路的牛牛

牛牛去犇犇老师家补课，出门的时候面向北方，但是现在他迷路了。虽然他手里有一张地图，但是他需要知道自己面向哪个方向，请你帮帮他。
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示转方向的次数N(N<=1000)。
接下来的一行包含一个长度为N的字符串，由L和R组成，L表示向左转，R表示向右转。

输出描述:
输出牛牛最后面向的方向，N表示北，S表示南，E表示东，W表示西。
示例1
输入
3
LRR
输出
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
矩形重叠：没有思路。。。。
*/