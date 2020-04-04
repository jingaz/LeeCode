#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


vector<vector<int>> CountSum(vector<int> num_array,
                             unordered_map<int, int> dict, int count,
                             int target) {

    vector<vector<int>> ret;
    if (count < 1 || num_array.empty()) {
        return ret;
    }

    // target>max_array 则返回ret
    int i = 0, max_array = 0, all_times = count;
    while (all_times > 0) {
        int times = min(dict[num_array[num_array.size() - 1 - i]], all_times);
        max_array += num_array[num_array.size() - 1 - i] * times;
        all_times -= times;
        i++;
    }
    if (target > max_array) {
        return ret;
    }

    // target<min_array 则返回ret
    i = 0;
    all_times = count;
    int min_array = 0;
    while (all_times > 0) {
        int times = min(dict[num_array[i]], all_times);
        min_array += num_array[i] * times;
        all_times -= times;
        i++;
    }
    if (target < min_array) {
        return ret;
    }

    if (count == 1) {
        if (binary_search(begin(num_array), end(num_array), target)) {
            ret.push_back(vector<int>{target});
            return ret;
        } else {
            return ret;
        }
    }

    // max_num 在元组中出现0 ~ min(dict[max_num], count)次
    int max_num = num_array.back();
    num_array.pop_back();
    for (int i = 0; i <= min(dict[max_num], count); i++) {

        vector<vector<int>> part_left;
        part_left = CountSum(num_array, dict, count - i, target - max_num * i);
        if (!part_left.empty()) {
            vector<int> tmp_right;
            for (int j = 1; j <= i; j++) {
                tmp_right.push_back(max_num);
            }
            for (auto numbers : part_left) {
                vector<int> tmp = tmp_right;
                for (int n_left : numbers) {
                    tmp.push_back(n_left);
                }
                ret.push_back(tmp);
            }
        }
        // 检查由 count 个 max_num 构成的元组是否满足条件
        else if (i == count && i * max_num == target) {
            vector<int> tmp;
            for (int j = 1; j <= count; j++) {
                tmp.push_back(max_num);
            }
            ret.push_back(tmp);
        }
    }
    return ret;
}

vector<vector<int>> FourSum(vector<int> &nums, int target) {
    vector<vector<int>> ret;
    if (nums.size() < 4) {
        return ret;
    }

    vector<int> num_array;
    // 将nums信息存入dict
    unordered_map<int, int> dict;
    for (int item : nums) {
        if (dict.find(item) != dict.end()) {
            dict[item]++;
        } else {
            dict[item] = 1;
            num_array.push_back(item);
        }
    }
    sort(num_array.begin(), num_array.end());

    cout << "\nsort for num_array: ";
    for (int i : num_array) {
        cout << i << ", ";
    }
    cout << "\b\b" << endl;

    return CountSum(num_array, dict, 4, target);
}

int main() {

    vector<vector<int>> testdata = {
        {1, 0, -1, 0, -2, 2, 0},
        {91277418,  66271374,  38763793,  4092006,   11415077,  60468277,
         1122637,   72398035,  -62267800, 22082642,  60359529,  -16540633,
         92671879,  -64462734, -55855043, -40899846, 88007957,  -57387813,
         -49552230, -96789394, 18318594,  -3246760,  -44346548, -21370279,
         42493875,  25185969,  83216261,  -70078020, -53687927, -76072023,
         -65863359, -61708176, -29175835, 85675811,  -80575807, -92211746,
         44755622,  -23368379, 23619674,  -749263,   -40707953, -68966953,
         72694581,  -52328726, -78618474, 40958224,  -2921736,  -55902268,
         -74278762, 63342010,  29076029,  58781716,  56045007,  -67966567,
         -79405127, -45778231, -47167435, 1586413,   -58822903, -51277270,
         87348634,  -86955956, -47418266, 74884315,  -36952674, -29067969,
         -98812826, -44893101, -22516153, -34522513, 34091871,  -79583480,
         47562301,  6154068,   87601405,  -48859327, -2183204,  17736781,
         31189878,  -23814871, -35880166, 39204002,  93248899,  -42067196,
         -49473145, -75235452, -61923200, 64824322,  -88505198, 20903451,
         -80926102, 56089387,  -58094433, 37743524,  -71480010, -14975982,
         19473982,  47085913,  -90793462, -33520678, 70775566,  -76347995,
         -16091435, 94700640,  17183454,  85735982,  90399615,  -86251609,
         -68167910, -95327478, 90586275,  -99524469, 16999817,  27815883,
         -88279865, 53092631,  75125438,  44270568,  -23129316, -846252,
         -59608044, 90938699,  80923976,  3534451,   6218186,   41256179,
         -9165388,  -11897463, 92423776,  -38991231, -6082654,  92275443,
         74040861,  77457712,  -80549965, -42515693, 69918944,  -95198414,
         15677446,  -52451179, -50111167, -23732840, 39520751,  -90474508,
         -27860023, 65164540,  26582346,  -20183515, 99018741,  -2826130,
         -28461563, -24759460, -83828963, -1739800,  71207113,  26434787,
         52931083,  -33111208, 38314304,  -29429107, -5567826,  -5149750,
         9582750,   85289753,  75490866,  -93202942, -85974081, 7365682,
         -42953023, 21825824,  68329208,  -87994788, 3460985,   18744871,
         -49724457, -12982362, -47800372, 39958829,  -95981751, -71017359,
         -18397211, 27941418,  -34699076, 74174334,  96928957,  44328607,
         49293516,  -39034828, 5945763,   -47046163, 10986423,  63478877,
         30677010,  -21202664, -86235407, 3164123,   8956697,   -9003909,
         -18929014, -73824245, -236727523}};
    for (auto it : testdata) {

        // it.back()作为target 方便测试
        int target = it.back();
        it.pop_back();

        for (auto ans : FourSum(it, target)) {
            cout << "[ ";
            for (int i : ans) {
                cout << i << ", ";
            }
            cout << "\b\b ]  ";
        };
        cout << endl;
    }
}