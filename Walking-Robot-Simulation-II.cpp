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
12    void change_direction_and_move(int &nx, int &ny, int &ndir){
13        nx -= (ndir == 0) - (ndir == 2);
14        ny -= (ndir == 1) - (ndir == 3);
15        ndir = (ndir+1)%4;
16        nx += (ndir == 0) - (ndir == 2);
17        ny += (ndir == 1) - (ndir == 3);
18    }
19
20    Robot(int width, int height) : curr_state(0, 0, 0) {
21        w = width;
22        h = height;
23        perimeter = (2*(width-2) + 2*(height-2) + 4);
24    }
25    
26    void step(int num) {
27        int x = curr_state.x, y = curr_state.y, dir = curr_state.dir;
28        int nx = x, ny = y, ndir = dir;
29
30        while(num --> 0){
31            nx += int(ndir == 0) - int(ndir == 2);
32            ny += int(ndir == 1) - int(ndir == 3);
33
34            if(nx >= w || nx < 0 || ny >= h || ny < 0){
35                change_direction_and_move(nx, ny, ndir);
36                break;
37            }
38        }
39
40        num %= perimeter;
41
42        while(num --> 0){
43            nx += (ndir == 0) - (ndir == 2);
44            ny += (ndir == 1) - (ndir == 3);
45
46            if(nx >= w || nx < 0 || ny >= h || ny < 0){
47                change_direction_and_move(nx, ny, ndir);
48            }
49        }
50
51        curr_state = {nx,ny,ndir};
52    }
53    
54    vector<int> getPos() {
55        return {curr_state.x, curr_state.y};
56    }
57    
58    string getDir() {
59        string direction[] = {"East", "North", "West", "South"};
60        return direction[curr_state.dir];
61    }
62};
63
64/**
65 * Your Robot object will be instantiated and called as such:
66 * Robot* obj = new Robot(width, height);
67 * obj->step(num);
68 * vector<int> param_2 = obj->getPos();
69 * string param_3 = obj->getDir();
70 */