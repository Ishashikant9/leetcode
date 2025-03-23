class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> result(2, 0);
        if (area == 0) {
            return result;
        }
        int a = static_cast<int>(sqrt(area));
        while (area % a != 0) {
            a--;
        }
        int b = area / a;
        result[0] = b;
        result[1] = a;
        return result;
    }
};
