//By: Kyle McCrea

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

//-----------------------------------------------------------
// Course structure
//-----------------------------------------------------------
struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;
};

//-----------------------------------------------------------
// Binary Search Tree node
//-----------------------------------------------------------
struct Node {
    Course course;
    Node* left;
    Node* right;

    Node(const Course& aCourse) {
        course = aCourse;
        left = nullptr;
        right = nullptr;
    }
};

//-----------------------------------------------------------
// Binary Search Tree class
//-----------------------------------------------------------
class BinarySearchTree {
private:
    Node* root;

    // Helper function to insert a course into the tree
    void insert(Node*& node, const Course& course) {
        if (node == nullptr) {
            node = new Node(course);
        }
        else if (course.courseNumber < node->course.courseNumber) {
            insert(node->left, course);
        }
        else {
            insert(node->right, course);
        }
    }

    // Helper function for inorder traversal
    void inOrder(Node* node) const {
        if (node == nullptr) {
            return;
        }

        inOrder(node->left);
        cout << node->course.courseNumber << ", " << node->course.courseTitle << endl;
        inOrder(node->right);
    }

    // Helper function to search for a course
    Course* search(Node* node, const string& courseNumber) const {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->course.courseNumber == courseNumber) {
            return &(node->course);
        }

        if (courseNumber < node->course.courseNumber) {
            return search(node->left, courseNumber);
        }

        return search(node->right, courseNumber);
    }

    // Helper function to free memory
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void Insert(const Course& course) {
        insert(root, course);
    }

    Course* Search(const string& courseNumber) const {
        return search(root, courseNumber);
    }

    void PrintCourseList() const {
        inOrder(root);
    }

    bool IsEmpty() const {
        return root == nullptr;
    }

    void Clear() {
        destroyTree(root);
        root = nullptr;
    }
};

//-----------------------------------------------------------
// Utility functions
//-----------------------------------------------------------

// Remove leading and trailing whitespace
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) {
        return "";
    }

    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

// Convert string to uppercase
string toUpperCase(string str) {
    for (char& c : str) {
        c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
    }
    return str;
}

// Split a line by commas
vector<string> split(const string& line) {
    vector<string> tokens;
    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(trim(token));
    }

    return tokens;
}

//-----------------------------------------------------------
// Load courses from file into BST
//-----------------------------------------------------------
bool loadCoursesFromFile(const string& fileName, BinarySearchTree& bst) {
    ifstream file(fileName);
    vector<Course> courses;
    vector<string> allCourseNumbers;
    string line;

    // Clear any previously loaded data
    bst.Clear();

    if (!file.is_open()) {
        cout << "Error: file could not be opened." << endl;
        return false;
    }

    // First pass: read all courses into a temporary vector
    while (getline(file, line)) {
        line = trim(line);

        // Skip blank lines
        if (line.empty()) {
            continue;
        }

        vector<string> tokens = split(line);

        // Need at least course number and course title
        if (tokens.size() < 2) {
            cout << "Error: invalid line format." << endl;
            cout << line << endl;
            bst.Clear();
            return false;
        }

        Course course;
        course.courseNumber = toUpperCase(tokens[0]);
        course.courseTitle = tokens[1];

        // Validate required fields
        if (course.courseNumber.empty() || course.courseTitle.empty()) {
            cout << "Error: missing course number or title." << endl;
            cout << line << endl;
            bst.Clear();
            return false;
        }

        // Add prerequisites if present
        for (size_t i = 2; i < tokens.size(); ++i) {
            string prereq = toUpperCase(tokens[i]);
            if (!prereq.empty()) {
                course.prerequisites.push_back(prereq);
            }
        }

        courses.push_back(course);
        allCourseNumbers.push_back(course.courseNumber);
    }

    file.close();

    // Validate that each prerequisite exists in the file
    for (const Course& course : courses) {
        for (const string& prereq : course.prerequisites) {
            bool found = false;

            for (const string& courseNumber : allCourseNumbers) {
                if (prereq == courseNumber) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Error: prerequisite " << prereq
                     << " for course " << course.courseNumber
                     << " does not exist in file." << endl;
                bst.Clear();
                return false;
            }
        }
    }

    // Insert validated courses into BST
    for (const Course& course : courses) {
        bst.Insert(course);
    }

    cout << "File loaded successfully." << endl;
    return true;
}

//-----------------------------------------------------------
// Print single course information
//-----------------------------------------------------------
void printCourseInformation(const BinarySearchTree& bst, const string& courseNumber) {
    string searchKey = toUpperCase(courseNumber);
    Course* course = bst.Search(searchKey);

    if (course == nullptr) {
        cout << "Course not found." << endl;
        return;
    }

    cout << course->courseNumber << ", " << course->courseTitle << endl;

    if (course->prerequisites.empty()) {
        cout << "Prerequisites: None" << endl;
        return;
    }

    cout << "Prerequisites: ";

    for (size_t i = 0; i < course->prerequisites.size(); ++i) {
        Course* prereqCourse = bst.Search(course->prerequisites[i]);

        if (prereqCourse != nullptr) {
            cout << prereqCourse->courseNumber << ", " << prereqCourse->courseTitle;
        }
        else {
            // Fallback in case prerequisite lookup fails unexpectedly
            cout << course->prerequisites[i];
        }

        if (i < course->prerequisites.size() - 1) {
            cout << "; ";
        }
    }

    cout << endl;
}

//-----------------------------------------------------------
// Display menu
//-----------------------------------------------------------
void displayMenu() {
    cout << endl;
    cout << "1. Load Data Structure." << endl;
    cout << "2. Print Course List." << endl;
    cout << "3. Print Course." << endl;
    cout << "9. Exit" << endl;
    cout << "What would you like to do? ";
}

//-----------------------------------------------------------
// Main
//-----------------------------------------------------------
int main() {
    BinarySearchTree courseTree;
    bool fileLoaded = false;
    int choice = 0;
    string fileName;
    string courseNumber;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {
        displayMenu();

        // Validate numeric menu input
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        cin.ignore(10000, '\n');

        switch (choice) {
        case 1:
            cout << "Enter file name: ";
            getline(cin, fileName);

            if (fileName.empty()) {
                cout << "Error: file name cannot be empty." << endl;
            }
            else {
                fileLoaded = loadCoursesFromFile(fileName, courseTree);
            }
            break;

        case 2:
            if (!fileLoaded) {
                cout << "Please load the file first." << endl;
            }
            else {
                cout << "Here is a sample schedule:" << endl;
                courseTree.PrintCourseList();
            }
            break;

        case 3:
            if (!fileLoaded) {
                cout << "Please load the file first." << endl;
            }
            else {
                cout << "What course do you want to know about? ";
                getline(cin, courseNumber);
                printCourseInformation(courseTree, courseNumber);
            }
            break;

        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;

        default:
            cout << choice << " is not a valid option." << endl;
            break;
        }
    }

    return 0;
}