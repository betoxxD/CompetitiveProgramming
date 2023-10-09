#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{ // the segment tree is stored like a heap array
private:
	vector<int> st, A; // recall that vi is: typedef vector<int> vi;
	int n;
	int left(int p) { return p << 1; } // same as binary heap operations
	int right(int p) { return (p << 1) + 1; }

	void build(int p, int L, int R)
	{							 // O(n log n)
		if (L == R)	 // as L == R, either one is fine
			st[p] = L; // store the index
		else
		{ // recursively compute the values
			build(left(p), L, (L + R) / 2);
			build(right(p), (L + R) / 2 + 1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = (A[p1] >= A[p2]) ? p1 : p2;
		}
	}

	int rmq(int p, int L, int R, int i, int j)
	{ // O(log n)
		if (i > R || j < L)
			return -1; // current segment outside query range
		if (L >= i && R <= j)
			return st[p]; // inside query range

		// compute the min position in the left and right part of the interval
		int p1 = rmq(left(p), L, (L + R) / 2, i, j);
		int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

		if (p1 == -1)
			return p2; // if we try to access segment outside query
		if (p2 == -1)
			return p1; // same as above
		return (A[p1] >= A[p2]) ? p1 : p2;
	} // as as in build routine

	int update_point(int p, int L, int R, int idx, int new_value)
	{
		// this update code is still preliminary, i == j
		// must be able to update range in the future!
		int i = idx, j = idx;

		// if the current interval does not intersect
		// the update interval, return this st node value!
		if (i > R || j < L)
			return st[p];

		// if the current interval is included in the update range,
		// update that st[node]
		if (L == i && R == j)
		{
			A[i] = new_value; // update the underlying array
			return st[p] = L; // this index
		}

		// compute the minimum pition in the
		// left and right part of the interval
		int p1, p2;
		p1 = update_point(left(p), L, (L + R) / 2, idx, new_value);
		p2 = update_point(right(p), (L + R) / 2 + 1, R, idx, new_value);

		// return the pition where the overall minimum is
		return st[p] = (A[p1] <= A[p2]) ? p1 : p2;
	}

public:
	void assignValues(const vector<int> &_A)
	{
		A = _A;
		n = (int)A.size();	 // copy content for local usage
		st.assign(4 * n, 0); // create large enough vector of zeroes
		build(1, 0, n - 1);	 // recursive build
	}

	int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); } // overloading

	int update_point(int idx, int new_value)
	{
		return update_point(1, 0, n - 1, idx, new_value);
	}
};

vector<int> positions;
vector<int> frecuencies;
vector<int> lastIds;

int main()
{
	int n, m, in, a, b, auxB, last = -100005, lastId, posicionAparicion = 0;
	int firstNumber, secondNumber, thirdNumber;
	int cont = 0;
	int result;
	int index;
	SegmentTree sg;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		if (n == 0)
		{
			break;
		}
		lastIds.assign(100005, 0);
		last = -100005;
		lastId = 0;
		positions.clear();
		frecuencies.clear();
		cont = 0;
		posicionAparicion = 0;
		scanf("%d", &m);
		while (n--)
		{
			scanf("%d", &in);
			if (in != last)
			{
				last = in;
				lastIds[posicionAparicion] = lastId;
				lastId = posicionAparicion;
				for (int i = 0; i < cont; i++)
				{
					positions.push_back(posicionAparicion);
					frecuencies.push_back(cont);
				}
				cont = 0;
			}
			cont++;
			posicionAparicion++;
		}
		lastIds[posicionAparicion] = lastId;
		for (int i = 0; i < cont; i++)
		{
			frecuencies.push_back(cont);
			positions.push_back(posicionAparicion);
		}
		sg.assignValues(frecuencies);
		/*for( int i : frecuencies ) {
			printf("%d ", i);
		}
		printf("\n"); */
		while (m--)
		{
			scanf("%d%d", &a, &b);
			firstNumber = 0;
			secondNumber = 0;
			thirdNumber = 0;
			if (a == b)
			{
				printf("%d\n", 1);
				continue;
			}
			if (a + 1 == b)
			{
				if (positions[a - 1] == positions[b - 1])
				{
					printf("%d\n", 2);
				}
				else
				{
					printf("%d\n", 1);
				}
				continue;
			}
			if (positions[a - 1] == positions[b - 1])
			{
				printf("%d\n", b - a + 1);
				continue;
			}
			a--;
			b--;
			if (a > 0 && frecuencies[a - 1] == frecuencies[a])
			{
				firstNumber = positions[a] - a;
				a = positions[a];
			}
			if (b < frecuencies.size() - 1 && frecuencies[b] == frecuencies[b + 1])
			{
				auxB = lastIds[positions[b]] - 1;
				// printf("%d \n", auxB);
				thirdNumber = b - auxB ;
				b = auxB;
			}
			// printf("a: %d b: %d\n", a + 1, b);
			index = sg.rmq(a, b);
			secondNumber = frecuencies[index];
			// printf("%d %d %d\n", firstNumber, secondNumber, thirdNumber);
			result = max(firstNumber, secondNumber);
			result = max(result, thirdNumber);
			printf("%d\n", result);
		}
	}
	return 0;
}
