#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int p[40003];
int q[100001];
int p_sum[40003];
//��ǥ�� 0�� ��ġ�� 20001�� ��´�.
vector<int> v;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int d, r, n;
	int temp;
	int left = 0;
	int right = 0;

	cin >> d >> r >> n;

	if (d > r) { // ������ ���̰� ���� �Ÿ����� �� ���
		for (int i = 0; i < n - 1; i++) {
			cout << p[i];
		}
		cout << p[0] << endl;
	}
	else {
		for (int i = 0; i < n; i++) { // ���� ���� ��ġ �ޱ�
			cin >> temp;
			p[temp + 20001]++;
		}
		for (int i = 0; i < n; i++) { // ���� ���� ��ġ �ޱ�
			cin >> q[i];
		}

		for (int i = 0; i < 40003; i++) {  // ������ ���� ��ġ �κ���
			if (i == 0) p_sum[i] = p[i];
			else p_sum[i] = p_sum[i - 1] + p[i];
		}
		// �� ������ ���Ͽ� ���� ��ġ�� �������� ���� �� �ִ�.

		double k = floor(sqrt(pow(r, 2) - pow(d, 2)));
		// ���� ���� ���� ����
		for (int i = 0; i < n; i++) { // ������ ������ �������� ���� ���� ���� ������

			if ((q[i] + 20001) - (int)k < 0) left = 0; // ���� ����(��)
			else left = q[i] + 20001 - k;

			if (q[i] + (20001 + k) > 40002) right = 40002; // ���� ����(��)
			else right = q[i] + 20001 + k;
			//cout << right << " " << left << endl;
			//cout << p_sum[right] << " " << p_sum[left-1] << endl;

			v.push_back(p_sum[right] - p_sum[left - 1]);
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < v.size()- 1; i++)
			cout << v[i] << " ";
		cout << v[v.size()-1];
		cout << endl;
	}
	return 0;
}


