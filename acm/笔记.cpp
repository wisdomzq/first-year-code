//优先队列
//对于基础类型 默认是大顶堆
//升序队列（小顶堆）
priority_queue<int> a; 
priority_queue <int,vector<int>,greater<int> > q;
//降序队列（大顶堆）（默认）
priority_queue <int,vector<int>,less<int> >q;
 

 //upper_bound用法
upper_bound(begin, end, value);
//在从小到大的排好序的数组中，在数组的 [begin, end) 区间中二分查找第一个大于value的数，找到返回该数字的地址，没找到则返回end。

lower_bound(begin, end, value);
//在从小到大的排好序的数组中，在数组的 [begin, end) 区间中二分查找第一个大于等于value的数，找到返回该数字的地址，没找到则返回end。

用greater<type>()重载
upper_bound(begin, end, value, greater<int>())
//在从大到小的排好序的数组中，在数组的 [begin, end) 区间中二分查找第一个小于value的数，找到返回该数字的地址，没找到则返回end。

lower_bound(begin, end, value, greater<int>())
//在从大到小的排好序的数组中，在数组的 [begin, end) 区间中二分查找第一个小于等于value的数，找到返回该数字的地址，没找到则返回end。

//归并排序
/*
算法思路
归并排序算法有两个基本的操作，一个是分，也就是把原数组划分成两个子数组的过程。另一个是治，它将两个有序数组合并成一个更大的有序数组。

将待排序的线性表不断地切分成若干个子表，直到每个子表只包含一个元素，这时，可以认为只包含一个元素的子表是有序表。
将子表两两合并，每合并一次，就会产生一个新的且更长的有序表，重复这一步骤，直到最后只剩下一个子表，这个子表就是排好序的线性表。
*/



//sort排序
/*sort()基本使用方法
 sort()函数可以对给定区间所有元素进行排序。它有三个参数sort(begin, end, cmp)，
其中begin为指向待sort()的数组的第一个元素的指针，end为指向待sort()的数组的最后一个元素的下一个位置的指针，
cmp参数为排序准则，cmp参数可以不写，如果不写的话，默认从小到大进行排序。
如果我们想从大到小排序可以将cmp参数写为greater<int>()就是对int数组进行排序，
当然<>中我们也可以写double、long、float等等。如果我们需要按照其他的排序准则，
那么就需要我们自己定义一个bool类型的函数来传入。*/
int num[10] = {6,5,9,1,2,8,7,3,4,0};
	sort(num,num+10,greater<int>());
/*自定义排序准则
 上面我们说到sort()函数可以自定义排序准则，以便满足不同的排序情况。
使用sort()我们不仅仅可以从大到小排或者从小到大排，还可以按照一定的准则进行排序。
比如说我们按照每个数的个位进行从大到小排序，我们就可以根据自己的需求来写一个函数作为排序的准则传入到sort()中。
*/
bool cmp(int x,int y){return x % 10 > y % 10;}
int num[10] = {65,59,96,13,21,80,72,33,44,99};
	sort(num,num+10,cmp);


//线性筛素数

bool isPrime[100000010];
//isPrime[i] == 1表示：i是素数
int Prime[6000010], cnt = 0;
//Prime存质数
void GetPrime(int n)//筛到n
{
	memset(isPrime, 1, sizeof(isPrime));
	//以“每个数都是素数”为初始状态，逐个删去
	isPrime[1] = 0;//1不是素数
	for(int i = 2; i <= n; i++)
	{
		if(isPrime[i])//没筛掉 
			Prime[++cnt] = i; //i成为下一个素数
		for(int j = 1; j <= cnt && i*Prime[j] <= n/*不超上限*/; j++) 
		{
        	//从Prime[1]，即最小质数2开始，逐个枚举已知的质数，并期望Prime[j]是(i*Prime[j])的最小质因数
            //当然，i肯定比Prime[j]大，因为Prime[j]是在i之前得出的
			isPrime[i*Prime[j]] = 0;  
			if(i % Prime[j] == 0)//i中也含有Prime[j]这个因子
				break; //重要步骤。见原理
                //逐个枚举加上最小质因数的限制保证每个合数都能被筛到
		}
	}
}

//字符串HASH    https://oi-wiki.org/string/hash/
/*
哈希其实是所有字符串操作中，笔者认为最简单的操作了（except输入输出qwq）。哈希的过程，其实可以看作对一个串的单向加密过程，并且需要保证所加的密不能高概率重复（就像不能让隔壁老王轻易地用它家的钥匙打开你家门一样qwq），通过这种方式来替代一些很费时间的操作。

比如，最常见的，当然就是通过哈希数组来判断几个串是否相同（洛谷P3370）。此处的操作呢，很简单，就是对于每个串，我们通过一个固定的转换方式，将相同的串使其的“密”一定相同，不同的串 尽量 不同。
此处有人指出：那难道不能先比对字符串长度，然后比对ASCLL码之和吗？事实上显然是不行的（比如ab和ba，并不是同一个串，但是如是做却会让其认为是qwq）。这种情况就叫做**

hash冲突**，并且在如此的单向加密哈希中，

hash冲突的情况在所难免（bzoj就有这种让你给出一组样例，使得一段哈希代码冲突的题，读者可以尝试尝试）。

而我们此处介绍的，即是最常见的一种哈希：进制哈希。进制哈希的核心便是给出一个固定进制

base，将一个串的每一个元素看做一个进制位上的数字，所以这个串就可以看做一个base进制的数，那么这个数就是这个串的哈希值；则我们通过比对每个串的的哈希值，即可判断两个串是否相同*/
using std::string;
const int M = 1e9 + 7;
const int B = 233;
typedef long long ll;
int get_hash(const string& s) {
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res = ((ll)res * B + s[i]) % M;
  }
  return res;
}
bool cmp(const string& s, const string& t) {
  return get_hash(s) == get_hash(t);
}