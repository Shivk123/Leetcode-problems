// Last updated: 5/28/2025, 9:47:59 PM
#include <vector>
#include <algorithm>

class Solution {
public:
    double separateSquares(std::vector<std::vector<int>>& squares) {
        double totalSurface = computeTotalSurface(squares);
        double lowerBound = getLowestY(squares);
        double upperBound = getHighestY(squares);
        double halfSurface = totalSurface / 2.0;
        double left = lowerBound, right = upperBound;
        constexpr double precision = 1e-6;

        while ((right - left) > precision) {
            double middle = (left + right) / 2.0;
            double calculatedArea = areaUnderLine(squares, middle);

            if (calculatedArea < halfSurface) {
                left = middle;
            } else {
                right = middle;
            }
        }
        return left;
    }

private:
    double computeTotalSurface(const std::vector<std::vector<int>>& squares) {
        double total = 0.0;
        for (const auto& s : squares) {
            total += static_cast<double>(s[2]) * s[2];
        }
        return total;
    }

    double getLowestY(const std::vector<std::vector<int>>& squares) {
        double minY = 1e9;
        for (const auto& s : squares) {
            minY = std::min(minY, static_cast<double>(s[1]));
        }
        return minY;
    }

    double getHighestY(const std::vector<std::vector<int>>& squares) {
        double maxY = 0.0;
        for (const auto& s : squares) {
            maxY = std::max(maxY, static_cast<double>(s[1] + s[2]));
        }
        return maxY;
    }

    double areaUnderLine(const std::vector<std::vector<int>>& squares, double yLimit) {
        double totalArea = 0.0;
        for (const auto& s : squares) {
            double baseY = s[1];
            double topY = baseY + s[2];
            double side = static_cast<double>(s[2]);

            if (yLimit <= baseY) continue;
            else if (yLimit >= topY) totalArea += side * side;
            else totalArea += side * (yLimit - baseY);
        }
        return totalArea;
    }
};
