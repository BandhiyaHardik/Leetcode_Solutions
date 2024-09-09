class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int id    = 0;
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;

        while(top <= down && left <= right) {
            if(id == 0) {
                for(int i = left; head != NULL && i <= right; i++) {
                    matrix[top][i] = head->val;
                    head = head->next;
                }
                top++;
            }

            if(id == 1) {
                for(int i = top; head != NULL && i <= down; i++) {
                    matrix[i][right] = head->val;
                    head = head->next;
                }
                right--;
            }

            if(id == 2) {
                for(int i = right; head != NULL && i >= left; i--) {
                    matrix[down][i] = head->val;
                    head = head->next;
                }
                down--;
            }

            if(id == 3) {
                for(int i = down; head != NULL && i >= top; i--) {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }

            id = (id+1)%4;
        }

        return matrix;
    }
};
