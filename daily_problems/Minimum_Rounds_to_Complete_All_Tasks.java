class Solution {
    public int minimumRounds(int[] tasks) {
        Map<Integer, Integer> difficultyFreqMap = new HashMap<>();
        for (int task: tasks){
            difficultyFreqMap.put(task, difficultyFreqMap.getOrDefault(task, 0)+1);
        }
        int ans = 0;
        for(Map.Entry<Integer, Integer> entry: difficultyFreqMap.entrySet()){
            int freq = entry.getValue();
            if(freq == 1){
                return -1;
            }
            if(freq %3 !=0){
                ans += freq/3+1;
            }else{
                ans += freq/3;
            }
        }
        return ans;
    }
}