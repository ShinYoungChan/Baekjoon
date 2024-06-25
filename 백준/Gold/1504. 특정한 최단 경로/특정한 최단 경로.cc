#include <iostream>
#include <queue>
#include <vector>

long long dijk(std::vector<std::vector<std::pair<int, int>>>& map, int vertex, int start, int dest) {
    std::vector<int> dist(vertex + 1, 2147400000);
    dist[start] = 0;
    std::priority_queue<std::pair<int, int>, 
        std::vector<std::pair<int, int>>,  
        std::greater<std::pair<int, int>>> pq;
    pq.push({ start, 0 });

    while (pq.empty() == false) {
        int currentV = pq.top().first;
        int currentD = pq.top().second;
        pq.pop();

        if (dist[currentV] < currentD) continue;

        for (int i = 0; i < map[currentV].size(); i++) {
            int next = map[currentV][i].first;
            int nextD = currentD + map[currentV][i].second;

            if (nextD < dist[next]) {
                dist[next] = nextD;
                pq.push({ next, nextD });
            }
        }
    }
    return dist[dest];
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int vertex = 0; int edge = 0;
    std::cin >> vertex >> edge;

    std::vector<std::vector<std::pair<int, int>>> map(vertex + 1);

    for (int i = 0; i < edge; i++) {
        int s = 0; int e = 0; int c = 0;
        std::cin >> s >> e >> c;
        map[s].push_back({ e, c });
        map[e].push_back({ s, c });
    }

    int node1 = 0; int node2 = 0;
    std::cin >> node1 >> node2;

    long long result1 = //1 -> node1 -> node2 -> N
        dijk(map, vertex, 1, node1) + dijk(map, vertex, node1, node2) + dijk(map, vertex, node2, vertex);
    long long result2 = //1 -> node2 -> node1 -> N
        dijk(map, vertex, 1, node2) + dijk(map, vertex, node2, node1) + dijk(map, vertex, node1, vertex);

    if (result1 >= 2147400000 || result2 >= 2147400000) {
        std::cout << -1;
        return 0;
    }

    if (result1 > result2) std::cout << result2;
    else std::cout << result1;
    return 0;
}