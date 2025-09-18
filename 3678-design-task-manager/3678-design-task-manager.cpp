class TaskManager {
public:
    unordered_map<int, int> taskUser, taskPriority;
    set<pair<int, int>, greater<pair<int, int>>> priorityTask;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto task : tasks){
            int userId = task[0], taskId = task[1], priority = task[2];
            
            taskUser[taskId] = userId;
            taskPriority[taskId] = priority;
            priorityTask.insert({priority, taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskUser[taskId] = userId;
        taskPriority[taskId] = priority;
        priorityTask.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto it = priorityTask.find({taskPriority[taskId], taskId});
        if(it != priorityTask.end())
            priorityTask.erase(it);
        taskPriority[taskId] = newPriority;
        priorityTask.insert({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        auto it = priorityTask.find({taskPriority[taskId], taskId});
        if(it != priorityTask.end())
            priorityTask.erase(it);
        taskUser.erase(taskId);
        taskPriority.erase(taskId);
    }
    
    int execTop() {
        if(priorityTask.empty())
            return -1;

        auto it = priorityTask.begin();
        int ans = taskUser[it->second];
        taskUser.erase(it->second);
        taskPriority.erase(it->second);
        priorityTask.erase(it);
        
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */