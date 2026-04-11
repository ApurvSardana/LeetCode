1class Robot {
2public:
3    int w,h,perimeter;
4    struct state{
5        int x;
6        int y;
7        int dir;
8
9        state(int x_, int y_, int dir_) : x(x_), y(y_), dir(dir_) {};
10    }curr_state;
11
12    Robot(int width, int height) : curr_state(0, 0, 0) {
13        w = width;
14        h = height;
15        perimeter = (2*(width-2) + 2*(height-2) + 4);
16    }
17    
18    void step(int num) {
19        int x = curr_state.x, y = curr_state.y, dir = curr_state.dir;
20        int nx = x, ny = y, ndir = dir;
21        // cout << nx << ", " << ny << ", " << ndir << " -> " << endl;
22        while(num --> 0){
23            nx += int(ndir == 0) - int(ndir == 2);
24            ny += int(ndir == 1) - int(ndir == 3);
25
26            if(nx >= w || nx < 0 || ny >= h || ny < 0){
27                nx -= (ndir == 0) - (ndir == 2);
28                ny -= (ndir == 1) - (ndir == 3);
29                ndir = (ndir+1)%4;
30                nx += (ndir == 0) - (ndir == 2);
31                ny += (ndir == 1) - (ndir == 3);
32                break;
33            }
34        }
35
36        num %= perimeter;
37
38        while(num --> 0){
39            nx += (ndir == 0) - (ndir == 2);
40            ny += (ndir == 1) - (ndir == 3);
41
42            if(nx >= w || nx < 0 || ny >= h || ny < 0){
43                nx -= (ndir == 0) - (ndir == 2);
44                ny -= (ndir == 1) - (ndir == 3);
45                ndir = (ndir+1)%4;
46                nx += (ndir == 0) - (ndir == 2);
47                ny += (ndir == 1) - (ndir == 3);
48            }
49        }
50
51        curr_state.x = nx;
52        curr_state.y = ny;
53        curr_state.dir = ndir;
54        // cout << curr_state.x << ", " << curr_state.y << ", " << curr_state.dir << endl;
55    }
56    
57    vector<int> getPos() {
58        return {curr_state.x, curr_state.y};
59    }
60    
61    string getDir() {
62        string direction[] = {"East", "North", "West", "South"};
63        return direction[curr_state.dir];
64    }
65};
66
67/**
68 * Your Robot object will be instantiated and called as such:
69 * Robot* obj = new Robot(width, height);
70 * obj->step(num);
71 * vector<int> param_2 = obj->getPos();
72 * string param_3 = obj->getDir();
73 */