class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int playersSize = players.size();
        int trainersSize = trainers.size();

        int matchings = 0;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0; int j = 0;
        while(i < playersSize && j < trainersSize)
        {
            if(players[i] <= trainers[j])
            {
                matchings++;
                i++;
            }
            j++;
        }

        return matchings;
        
    }
};