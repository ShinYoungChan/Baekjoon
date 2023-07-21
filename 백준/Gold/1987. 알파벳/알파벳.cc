#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	char _a;
	int _r, _c;
	int _dir;
public:
	Node() {}
	Node(char a, int r, int c, int R, int C) {
		_dir = 15;
		_a = a;
		_r = r;
		_c = c;
		/*if (_r == 0)
			_dir &= ~1;
		if (_r == R - 1)
			_dir &= ~2;
		if (_c == 0)
			_dir &= ~4;
		if (_c == C - 1)
			_dir &= ~8;*/
	}
	~Node() {}
public:
	inline bool isBlocking(void) {
		return !_dir;
	}
};
int main(void) {
	int R, C;
	char a;
	cin >> R >> C;
	vector<bool> isVisited(27, false);
	vector<vector<Node*>> nodes(R);
	for (int i = 0; i < R; i++) {
		nodes[i].resize(C);
		for (int j = 0; j < C; j++) {
			cin >> a;
			nodes[i][j] = new Node(a - 65, i, j, R, C);
		}
	}
	vector<Node*> queue(1, nodes[0][0]);
	int maxNum = 0;
	int curr = 0;
	isVisited[nodes[0][0]->_a] = true;
	while (queue.size()) {
		auto node = queue.back();
		if (!node->isBlocking()) {
			int r, c;
			bool chk = false;
			for (int i = 0; i < 4; i++) {
				if (node->_dir & (1 << i)) {
					r = node->_r;
					c = node->_c;
					if (i & 2)	c += ((i & 1) << 1) - 1;
					else		r += ((i & 1) << 1) - 1;

					node->_dir &= ~(1 << i);
					if (r < 0 || r >= R || c < 0 || c >= C)
						continue;
					if (isVisited[nodes[r][c]->_a] ||
						(queue.size() > 1 && nodes[r][c] == queue[queue.size() - 2]))
						continue;

					isVisited[nodes[r][c]->_a] = true;
					queue.push_back(nodes[r][c]);
					chk = true;
					curr++;
					break;
				}
			}
			if (chk) continue;
		}
		isVisited[node->_a] = false;
		node->_dir = 15;
		if (maxNum < curr)
			maxNum = curr;
		curr--;
		queue.pop_back();
	}
	printf("%d\n", maxNum + 1);
	return 0;
}