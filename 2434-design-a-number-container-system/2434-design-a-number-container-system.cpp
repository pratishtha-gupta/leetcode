class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indnum.find(index)!=indnum.end())
        {
            int prev = indnum[index];
            indexes[prev].erase(index);
            if(indexes[prev].empty())
            {
                indexes.erase(prev);
            }

        }
        indnum[index]=number;
        indexes[number].insert(index);
    }
    
    int find(int number) {
        if(indexes.find(number)!=indexes.end())
        {
            return *indexes[number].begin();
        }
        return -1;
    }
private:
 unordered_map <int,set<int>> indexes;
 unordered_map <int , int> indnum;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */