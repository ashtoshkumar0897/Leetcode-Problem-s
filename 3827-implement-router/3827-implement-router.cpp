//Approach (Queue for FIFO, Map for quick retrieval and sorted vector for binary search)
// T.C. : 
// addPacket()       -> O(k) worst-case (due to forwardPacket() + vector erase at front)
// forwardPacket()   -> O(k) worst-case (erase from vector front for destination timestamps)
// getCount()        -> O(log k) per query (binary search in vector)
// k = number of packets for a particular destination

// S.C. : 
// O(MAX_SIZE) total
// packetStore     -> O(MAX_SIZE)
// que             -> O(MAX_SIZE * key length)
// destTimestamps  -> O(MAX_SIZE)

class Router {
private:
    int MAX_SIZE;  // memory limit in number of packets
    unordered_map<string, vector<int>> packetStore;  // key -> {source, dest, timestamp}
    unordered_map<int, vector<int>> destTimestamps;  // destination -> sorted timestamps
    queue<string> que;  // FIFO order of packet keys

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        MAX_SIZE = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        // Duplicate check
        if (packetStore.find(key) != packetStore.end()) {
            return false;
        }

        // Evict oldest if at capacity
        if ((int)packetStore.size() >= MAX_SIZE) {
            forwardPacket();
        }

        // Store packet
        packetStore[key] = {source, destination, timestamp};
        que.push(key);

        // Insert timestamp in sorted order for binary search
        auto &vec = destTimestamps[destination];
        vec.insert(lower_bound(vec.begin(), vec.end(), timestamp), timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (packetStore.empty())
            return {}; // nothing to forward

        string key = que.front();
        que.pop();

        vector<int> packet = packetStore[key];
        packetStore.erase(key);

        int dest = packet[1];
        int timestamp = packet[2];

        // Remove the matching timestamp (first occurrence)
        auto &vec = destTimestamps[dest];
        auto it = lower_bound(vec.begin(), vec.end(), timestamp);
        if (it != vec.end() && *it == timestamp) {
            vec.erase(it);
        }

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimestamps.find(destination);
        if (it == destTimestamps.end() || it->second.empty())
            return 0;

        const auto &vec = it->second;
        int leftIdx  = lower_bound(vec.begin(), vec.end(), startTime) - vec.begin();
        int rightIdx = upper_bound(vec.begin(), vec.end(), endTime) - vec.begin();

        return rightIdx - leftIdx;
    }
};




/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */