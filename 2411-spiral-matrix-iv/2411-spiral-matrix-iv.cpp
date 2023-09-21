/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left = 0;
        int right = n;
        int top = 0;
        int bottom = m;

        vector<vector<int>> res(m, vector<int> (n, -1));
        
        while(left < right && top < bottom){
            for(int i=left; i<right; i++){
                res[top][i] = head->val;
                if (head->next == NULL){
                    return res;
                }
                head = head->next;
            }
            top++;

            for(int i=top; i<bottom; i++){
                res[i][right-1] = head->val;
                if (head->next == NULL){
                    return res;
                }
                head = head->next;
            }
            right--;

            for(int i=right-1; i>=left; i--){
                res[bottom-1][i] = head->val;
                if (head->next == NULL){
                    return res;
                }
                head = head->next;
            }
            bottom--;

            for(int i=bottom-1; i>=top; i--){
                res[i][left] = head->val;
                if (head->next == NULL){
                    return res;
                }
                head = head->next;
            }
            left++;
        }
        return res;
    }
};