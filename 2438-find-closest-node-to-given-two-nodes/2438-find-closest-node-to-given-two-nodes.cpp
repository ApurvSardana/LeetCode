class Solution {
public:
    vector<int> vis;
    bool possible(vector<int> &edges, int source, int target){
        if(source == target) return true;
        if(edges[source] == -1 || vis[source] == 1) return false;

        vis[source] = 1;
        return possible(edges, edges[source], target);
    }

    int distance(vector<int> &edges, int source, int target, int dis){
        if(source == target) return dis;

        return distance(edges, edges[source], target, dis+1); 
    }

    void mark_nodes(vector<int> &edges, int source){
        if(vis[source] == 1) return;
        vis[source] = 1;

        if(edges[source] != -1) mark_nodes(edges, edges[source]);
    }

    int find_common_point(vector<int> &edges, int source){
        if(vis[source] == 1) return source;

        if(vis[source] == 2) return -1;

        vis[source] = 2;

        if(edges[source] == -1) return -1;
        else return find_common_point(edges, edges[source]);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size(); int ans = -1; int min_dis = INT_MAX;
        vis.assign(n, 0);
        if(node1 == node2) return node1;

        if(edges[node1] == edges[node2] && edges[node1] == -1) return -1;

        if(edges[node1] == -1) return (possible(edges, node2, node1)) ? node1 : -1;

        if(edges[node2] == -1) return (possible(edges, node1, node2)) ? node2 : -1;

        int md1 = INT_MAX;
        if(possible(edges, node1, node2)){
            md1 = distance(edges, node1, node2, 0);
            if(md1 < min_dis){
                min_dis = md1;
                ans = node2;
            }

            else if(md1 == min_dis){
                ans = min(ans, node2);
            }
        }

        vis.assign(n, 0);
        int md2 = INT_MAX;
        if(possible(edges, node2, node1)){
            md2 = distance(edges, node2, node1, 0);
            if(md2 < min_dis){
                min_dis = md2;
                ans = node1;
            }

            else if(md2 == min_dis){
                ans = min(ans, node1);
            }
        }

        int md3 = INT_MAX;
        vis.assign(n, 0);

        mark_nodes(edges, node1);
        int cm = find_common_point(edges, node2);
        if(cm != -1){
            md3 = max(distance(edges, node2, cm, 0), distance(edges, node1, cm, 0));
            if(md3 < min_dis){
                min_dis = md3;
                ans = cm;
            }

            else if(md3 == min_dis){
                ans = min(ans, cm);
            }
        }

        int md4 = INT_MAX;
        vis.assign(n, 0);
        mark_nodes(edges, node2);
        int cm2 = find_common_point(edges, node1);
        if(cm2 != -1){
            md4 = max(distance(edges, node1, cm2, 0), distance(edges, node2, cm2, 0));
            if(md4 < min_dis){
                min_dis = md4;
                ans = cm2;
            }

            else if(md4 == min_dis){
                ans = min(ans, cm2);
            }
        }

        return ans;
    }
};