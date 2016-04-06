#include <cstdio>
#include <algorithm>
#define N 70000
using namespace std;

struct seg{
	int lsum, rsum, msum;//, sum;
};

int arr[N+1];
seg tree[4*N + 1];
int sum[N+1];
// Building segment tree
void build(int node, int l, int r) {
	if(l == r)
	 tree[node] = ( (seg){ arr[l], arr[l], arr[l] } );
	else {
		build( 2 * node, l, (l + r)/2 );
		build( 2 * node + 1, (l + r)/2 + 1, r );
		seg left = tree[2 * node];
		seg right = tree[2 * node + 1];
		//tree[node].sum = left.sum + right.sum;
		tree[node].lsum = max(left.lsum, sum[(l + r)/2] - sum[l-1] + right.lsum);
		tree[node].rsum = max(right.rsum, sum[r] - sum[(l + r)/2] + left.rsum);
		tree[node].msum = max(left.msum, max(right.msum, left.rsum + right.lsum));
		//tree[node].lsum = max(tree[ 2 * node].lsum, tree[2 * node].msum + tree[ 2 * node + 1].lsum);
		//tree[node].rsum = max(tree[ 2 * node + 1].rsum, tree[2 * node + 1].msum + tree[2 * node].rsum);
	}
}

seg query(int node, int a, int b, int range_a, int range_b){
  //cout<<"entered query : Querying "<<a<<" "<< b <<endl;
  int m = (a + b)/2;
	if(range_a == a && range_b == b)
		return tree[node];
	// // as j being the largest index in the given range i.e.,(i,j)
	// if j<=m then we can completely depend on the left child's data ( to obt the sum for given range)
	else if(range_b <= m) 
		return query( 2 * node, a, m, range_a, range_b);
	// as i being the smallest index in the given range i.e.,(i,j)
	// if i > m then we can completely depend on the right child's data ( to obt the sum for given range)
	// AND ALSO , if it were i>=m then i == j 
	if(range_a > m)	
		return query( 2 * node + 1, m+1, b, range_a, range_b);
	// left_result_query && right_result_query
	// obtain max sum by data available with left and right 
	seg left_result = query( 2*node, a, m, range_a, m);
	seg right_result = query(2*node + 1, m+1, b, m+1, range_b);
	//seg left = tree[2*node], right = tree[2*node+1];
	// this return call is(very important) to obtain the max sum from splitting the query into two halves
	// i.e., to merge the sum obtained rom the left & right (queries).  
	// A G G R E G A T I O N 
return ((seg){
	max(left_result.lsum, sum[m] - sum[range_a - 1] + right_result.lsum),
	max(right_result.rsum, sum[b] - sum[m] + left_result.rsum),
	max(left_result.msum, max(right_result.msum, left_result.rsum + right_result.lsum))
  //left_result.sum + right_result.sum
 });
}

int main(){
	int n;
	//ios_base::sync_with_stdio(false);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", arr + i);
		if(i == 0) sum[i] = arr[i];
		else 
     sum[i] = sum[i-1] + arr[i];
	}
	build(1, 0, n-1);
	int Q;
	scanf("%d", &Q);
	int l,r;
	while(Q--){
		scanf( "%d%d", &l, &r);
		printf( "%d\n",query(1, 0, n-1, --l, --r).msum);
		// query returns a node <structure>
		// we are accessing the varible msum of that node
		// as msum is the maximum sum
	}
	return 0;
}
