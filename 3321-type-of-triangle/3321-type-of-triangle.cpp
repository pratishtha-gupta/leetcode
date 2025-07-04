class Solution {
public:
    bool is_triangle_valid(int side1, int side2, int side3) {
    return (side1 + side2 > side3);
}

string determine_triangle_type(int side1, int side2, int side3) {
    if (side1 == side2 && side2 == side3) {
        return "equilateral";
    } else if (side1 == side2 || side2 == side3 || side1 == side3) {
        return "isosceles";
    } else {
        return "scalene";
    }
}

string triangleType(vector<int>& sides) {
    // Sort the sides for easier comparison
    sort(sides.begin(), sides.end());

    // Check for the validity of the triangle
    if (!is_triangle_valid(sides[0], sides[1], sides[2])) {
        return "none";
    }

    // Return the type of the triangle
    return determine_triangle_type(sides[0], sides[1], sides[2]);
}
};