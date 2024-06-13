class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {

        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int totalMoves = 0;
        for (int i = 0; i < seats.size(); ++i) {
            totalMoves += std::abs(seats[i] - students[i]);
        }
        
        return totalMoves;
    }
};