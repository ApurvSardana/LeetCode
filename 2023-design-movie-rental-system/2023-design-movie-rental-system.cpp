class MovieRentingSystem {
public:
    //movies[i] = {price, shop};
    unordered_map<int, set<pair<int, int>>> movies;
    //shops[i] = {movie, price}
    unordered_map<int, unordered_map<int, int>> shops;
    //rented has {price, shop, movie}
    set<vector<int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &entry : entries){
            int shop = entry[0], movie = entry[1], price = entry[2];

            movies[movie].insert({price,shop});
            shops[shop][movie] = price;
        }
    }
    
    vector<int> search(int movie) {
        auto &st = movies[movie];

        vector<int> ans;
        auto it = st.begin();
        int count = 0;
        while(it != st.end() && count < 5){
            ans.push_back(it->second);
            count++;
            it++;
        }

        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = shops[shop][movie];

        movies[movie].erase({price, shop});
        //shops[shop].erase(movie);
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = shops[shop][movie];

        movies[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;

        int count = 0;
        for(auto &movies : rented){
            ans.push_back({movies[1], movies[2]});
            count++;
            if(count == 5) break;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */