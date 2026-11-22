#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Convert text to lowercase
string toLowerCase(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = tolower((unsigned char)text[i]);
    }

    return text;
}

// Linear Search Function
int linearSearch(string arr[], int size, string target)
{
    target = toLowerCase(target);

    for (int i = 0; i < size; i++)
    {
        if (toLowerCase(arr[i]) == target)
        {
            return i;
        }
    }

    return -1;
}

// Display remaining objects
void displayRemaining(string required[], bool found[], int size)
{
    cout << "\\nObjects Remaining:\\n";

    bool remaining = false;

    for (int i = 0; i < size; i++)
    {
        if (!found[i])
        {
            cout << "- " << required[i] << endl;
            remaining = true;
        }
    }

    if (!remaining)
    {
        cout << "All objects have been found!\\n";
    }
}

int main()
{
    const int SIZE = 10;
    const int TARGETS = 5;

    // Objects inside the room
    string objects[SIZE] = {
        "book", "clock", "key", "phone", "bag",
        "pencil", "cup", "watch", "ball", "camera"
    };

    // Objects the player must find
    string required[TARGETS] = {
        "key", "phone", "clock", "camera", "watch"
    };

    // Track found objects
    bool found[TARGETS] = { false, false, false, false, false };

    int score = 0;
    int attempts = 10;

    string guess;

    cout << "================================\\n";
    cout << "      HIDDEN OBJECT GAME\\n";
    cout << "================================\\n";

    cout << "\\nWelcome to the Hidden Object Game!\\n";
    cout << "You have only ONE LEVEL.\\n";

    cout << "\\nFind these 5 hidden objects:\\n";

    for (int i = 0; i < TARGETS; i++)
    {
        cout << "- " << required[i] << endl;
    }

    cout << "\\nYou have 10 attempts!\\n";

    // Main game loop
    while (score < TARGETS && attempts > 0)
    {
        cout << "\\n--------------------------------\\n";

        displayRemaining(required, found, TARGETS);

        cout << "\\nEnter an object name: ";
        cin >> guess;

        // Count the attempt
        attempts--;

        // Search using Linear Search
        int index = linearSearch(objects, SIZE, guess);

        if (index != -1)
        {
            // Check if the object is required
            int targetIndex = linearSearch(required, TARGETS, guess);

            if (targetIndex != -1)
            {
                if (!found[targetIndex])
                {
                    found[targetIndex] = true;
                    score++;

                    cout << "\\nCorrect! You found the object!\\n";
                    cout << "Found Object: " << required[targetIndex] << endl;
                }
                else
                {
                    cout << "\\nYou already found this object!\\n";
                }
            }
            else
            {
                cout << "\\nThis object is not on your target list!\\n";
            }
        }
        else
        {
            cout << "\\nObject does not exist in the room!\\n";
        }

        cout << "\\nScore: " << score << "/" << TARGETS << endl;
        cout << "Remaining Attempts: " << attempts << endl;
    }

    // Final game result
    cout << "\\n================================\\n";
    cout << "           GAME OVER\\n";
    cout << "================================\\n";

    if (score == TARGETS)
    {
        cout << "Congratulations! You won!\\n";
        cout << "You found all hidden objects!\\n";
    }
    else
    {
        cout << "You lost! Try again.\\n";
    }

    cout << "\\nFinal Score: " << score << "/" << TARGETS << endl;
    cout << "Total Attempts Used: " << 10 - attempts << endl;

    cout << "\\n================================\\n";

    return 0;
}
