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
////第二种解法，先排序
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
//		guy[j].second = j;//排序后记录这个人原来的位置
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
//		each_count = (y - k)*(n / y);//计算n/y个循环节中的个数
//		if (n%y >= k) {//计算最后凑不齐一个循环节，剩下的余数大于K的个数
//			if (k)
//				each_count += n%y - k + 1;//如果k不等于0
//			else
//				each_count += n%y;//如果k等于0，上面的计算方式就多算了一个
//		}
//		count += each_count;
//	}
//	cout << count << endl;
//}

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
//连循环都不能用，所以这种方式不行
//#include<iostream>
//
//using namespace std;
//
//int main() {
//	long long l, r;
//	cin >> l >> r;
//	long long count = 0, i = 0;
//	int t = 0;//t表示余数
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