// Last updated: 5/28/2025, 9:53:10 PM
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        auto getMinimumDistance = [](int minEdge, int maxEdge, int centerCoord) -> int {
            if (centerCoord >= minEdge && centerCoord <= maxEdge) {
                return 0;
            }
            return centerCoord < minEdge ? minEdge - centerCoord : centerCoord - maxEdge;
        };

        int deltaX = getMinimumDistance(x1, x2, xCenter);
        int deltaY = getMinimumDistance(y1, y2, yCenter);
        return deltaX * deltaX + deltaY * deltaY <= radius * radius;
    }
};