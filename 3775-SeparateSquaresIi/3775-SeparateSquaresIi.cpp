// Last updated: 5/28/2025, 9:47:58 PM
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    struct Interval {
        double y;
        double x_start, x_end;
        int type;
    };

    struct SegmentTree {
        int size;
        vector<int> count;
        vector<double> covered_length;
        vector<double> x_coordinates;

        SegmentTree(const vector<double>& x_vals) {
            x_coordinates = x_vals;
            size = x_vals.size() - 1;
            count.assign(4 * size, 0);
            covered_length.assign(4 * size, 0.0);
        }

        void update(int node, int left, int right, int ql, int qr, int value) {
            if (qr < left || right < ql)
                return;

            if (ql <= left && right <= qr) {
                count[node] += value;
            } else {
                int mid = (left + right) / 2;
                update(node * 2, left, mid, ql, qr, value);
                update(node * 2 + 1, mid + 1, right, ql, qr, value);
            }

            if (count[node] > 0) {
                covered_length[node] =
                    x_coordinates[right + 1] - x_coordinates[left];
            } else {
                covered_length[node] = (left == right)
                                           ? 0.0
                                           : covered_length[node * 2] +
                                                 covered_length[node * 2 + 1];
            }
        }

        double getCoveredLength() { return covered_length[1]; }
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Interval> intervals;
        vector<double> x_vals;

        for (auto& square : squares) {
            double x1 = square[0], y1 = square[1], side = square[2];
            double x2 = x1 + side, y2 = y1 + side;

            x_vals.push_back(x1);
            x_vals.push_back(x2);

            intervals.push_back({y1, x1, x2, 1});
            intervals.push_back({y2, x1, x2, -1});
        }

        sort(x_vals.begin(), x_vals.end());
        x_vals.erase(unique(x_vals.begin(), x_vals.end()), x_vals.end());

        map<double, int> xIndex;
        for (int i = 0; i < x_vals.size(); i++) {
            xIndex[x_vals[i]] = i;
        }

        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) { return a.y < b.y; });

        SegmentTree segTree(x_vals);
        double totalArea = 0, prevY = intervals[0].y;
        vector<pair<double, double>> area_prefix;

        for (auto& event : intervals) {
            double y = event.y;
            double covered = segTree.getCoveredLength();
            totalArea += covered * (y - prevY);
            area_prefix.emplace_back(y, totalArea);

            segTree.update(1, 0, x_vals.size() - 2, xIndex[event.x_start],
                           xIndex[event.x_end] - 1, event.type);
            prevY = y;
        }

        double halfArea = totalArea / 2.0;
        double y_low = 0.0, y_high = 0.0, area_low = 0.0, area_high = 0.0;

        for (size_t i = 0; i < area_prefix.size(); ++i) {
            if (area_prefix[i].second >= halfArea) {
                if (i == 0)
                    return area_prefix[i].first;

                y_low = area_prefix[i - 1].first;
                y_high = area_prefix[i].first;
                area_low = area_prefix[i - 1].second;
                area_high = area_prefix[i].second;
                break;
            }
        }

        return y_low + (halfArea - area_low) * (y_high - y_low) /
                           (area_high - area_low);
    }

    int countSquares(vector<vector<int>>& squares) { return squares.size(); }

    int findMaxX(vector<vector<int>>& squares) {
        int maxX = 0;
        for (auto& square : squares) {
            maxX = max(maxX, square[0] + square[2]);
        }
        return maxX;
    }

    int findMinY(vector<vector<int>>& squares) {
        int minY = INT_MAX;
        for (auto& square : squares) {
            minY = min(minY, square[1]);
        }
        return minY;
    }

    bool areSquaresOverlapping(vector<int>& square1, vector<int>& square2) {
        return !(square1[0] + square1[2] <= square2[0] ||
                 square2[0] + square2[2] <= square1[0] ||
                 square1[1] + square1[2] <= square2[1] ||
                 square2[1] + square2[2] <= square1[1]);
    }

    double calculateTotalArea(vector<vector<int>>& squares) {
        double area = 0;
        for (auto& square : squares) {
            area += square[2] * square[2];
        }
        return area;
    }

    int findMaxY(vector<vector<int>>& squares) {
        int maxY = 0;
        for (auto& square : squares) {
            maxY = max(maxY, square[1] + square[2]);
        }
        return maxY;
    }

    int findMinX(vector<vector<int>>& squares) {
        int minX = INT_MAX;
        for (auto& square : squares) {
            minX = min(minX, square[0]);
        }
        return minX;
    }

    vector<int> computeBoundingBox(vector<vector<int>>& squares) {
        int minX = findMinX(squares);
        int maxX = findMaxX(squares);
        int minY = findMinY(squares);
        int maxY = findMaxY(squares);
        return {minX, minY, maxX, maxY};
    }
};
