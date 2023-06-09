/*
Ninja's Trip
calculate minimum cost to travel for the days in array 
by purchasing tickets of 1 day 7 day and 30 days
Example:
Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
*/

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int ans=0;
    queue<pair<int,int>>month;
    queue<pair<int,int>>week;

    for(int day:days){
        
        // step 1: remove expire days 
        while(!month.empty() && month.front().first+30<=day){
            month.pop();
        }
        while(!week.empty() && week.front().first+7<=day){
            week.pop();
        }

        //step 2: add cost for current day
        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));

        // step 3: ans update
        ans =min(ans + cost[0], min(week.front().second, month.front().second));
        
    }
        return ans;
}