#define ll long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


struct res {
    vector<pair<ll, ll>> gaps;
    pair<ll, ll> longest_gap;
    ll missing_count;
};


res find_missing_ranges(vector<ll> frames){
    unordered_set<ll> f(frames.begin(), frames.end());
    ll maxi = -1;
    for(ll frame : frames){
        maxi = max(maxi, frame);
    }
    bool gap_started = false; ll gap_started_at;
    vector<pair<ll, ll>> gaps;
    pair<ll, ll> longest_gap; ll longest_gap_yet = 0, current_gap = 0;
    ll missing_count = 0;
    for(ll i = 1; i <= maxi; i++){
        if(f.find(i) != f.end()){ // found (lookup is O(1) in unordered sets)
            if(gap_started){
                gap_started = false;
                gaps.push_back(make_pair(gap_started_at, i - 1));
                current_gap = i - 1 - gap_started_at;
                if(current_gap > longest_gap_yet){
                    longest_gap_yet = current_gap;
                    longest_gap = make_pair(gap_started_at, i - 1);
                }
            } else{
                continue;
            }
        } else{
            if(!gap_started){
                gap_started = true;
                gap_started_at = i;
            }
            missing_count++;
        }
    }
    return {
        gaps, longest_gap, missing_count
    };
}

int main() {
    res result = find_missing_ranges({1, 2, 3, 5, 10, 11, 12, 8});
    cout << "gaps: [";
    for(auto gap: result.gaps){
        cout << '[' << gap.first << ", " << gap.second << "],";
    }
    cout << "]" << endl;
    cout << "longest_gap: [" << result.longest_gap.first << ", " << result.longest_gap.second << "]" << endl;
    cout << "missing_count: " << result.missing_count << endl;
    return 0;
}
