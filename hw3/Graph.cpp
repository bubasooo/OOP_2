//
// Created by c4lculater on 14.12.2022.
//
#include <iostream>
#include <vector>
#include <queue>
#include <xmath.h>

using namespace std;



class Graph {
public:
    Graph(vector<vector<int> >& matrix) {
        V = matrix[0].size();
        for(int i = 0; i < matrix[i].size();i++) {
            vector<pair<int, int> > a;
            lc.push_back(a);
            for(int j = 0; j < matrix[i].size();j++) {
                if (matrix[i][j] != 0) {
                    lc[i].push_back({matrix[i][j], j});
                    E.push({-matrix[i][j], {i, j}});
                }
            }
            inced.push_back(lc[i].size());
        }
    }


    vector<int> getNumNeghb() {
        return inced;
    }

    int getNumNeighb(int V) {
        return inced[V];
    }

    void minOstov() { //Караскула
        vector<bool> visited(V, false);
        while(!E.empty()) {
            auto edje = E.top();
            E.pop();
            if(!visited[edje.second.first] || !visited[edje.second.second]) {
                visited[edje.second.first] = true;
                visited[edje.second.second] = true;
                ostov.push_back(edje);
            }
        }
    }

    vector<int> deysktra(int startV) {
        vector<int> distanceDeyskstra(V,INF);
        priority_queue<pair<int,int> > q;
        vector<bool> processed(V,false);


        distanceDeyskstra[startV] = 0;
        q.push({0, startV});

        while(!q.empty()) {
            int current = q.top().second;
            q.pop();
            if(processed[current])
                continue;
            processed[current] = true;
            for(auto neighs : lc[current]) {
                int neigboor = neighs.first;
                int distFromCurrrent = neighs.second;
                if(distanceDeyskstra[current] + distFromCurrrent < distanceDeyskstra[neigboor]) {
                    distanceDeyskstra[neigboor] = distanceDeyskstra[current] + distFromCurrrent;
                    q.push({-distanceDeyskstra[neigboor], neigboor});
                }
            }
        }

    }

    vector<int> BFS(int startV, bool typeGraph = true) {
        vector<int> distanceBFS(V, 0);
        vector<bool> visited(V, false);
        queue<int> q;

        visited[startV] = true;
        distanceBFS[startV] = 0;
        q.push(startV);
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            for(auto neigh: lc[current]) {
                if(visited[neigh.second]) continue;
                visited[neigh.second] = true;
                distanceBFS[neigh.second] = distanceBFS[current] + 1;
                q.push(neigh.second);
            }
        }
        return distanceBFS;
    }
private:
    bool OTREE = false;
    bool GRAPH = true;
    int V = 0;
    vector<pair<int,pair<int,int> > > ostov;
    vector<vector<pair<int,int> > > lc;
    priority_queue<pair<int, pair<int,int> > > E;
    vector<int> inced;
};
