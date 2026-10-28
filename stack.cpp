#include <iostream>
#include <string>
#include <stack>

using namespace std;

class TextEditor {
private:
    string text;
    stack<string> undoStack; // Stack storing previous states of text

public:
    TextEditor() {
        text = "";
    }

    // Append text and save current state to stack before changing
    void typeText(const string& newText) {
        undoStack.push(text); // Push state onto stack (LIFO)
        text += newText;
        cout << "[Typed]: \"" << newText << "\" | Current Text: \"" << text << "\"\n";
    }

    // Revert to previous state using stack pop
    void undo() {
        if (undoStack.empty()) {
            cout << "[Undo Failed]: No actions left to undo!\n";
            return;
        }

        text = undoStack.top();
        undoStack.pop();
        cout << "[Undo Performed] | Restored Text: \"" << text << "\"\n";
    }

    void display() const {
        cout << "--> Current Document Content: \"" << text << "\"\n\n";
    }
};

int main() {
    TextEditor editor;

    cout << "--- C++ STACK DEMONSTRATION: TEXT EDITOR UNDO SYSTEM ---\n\n";

    editor.typeText("Data ");
    editor.typeText("Structures ");
    editor.typeText("Stack ");
    editor.display();

    cout << "--- Pressing Undo --- \n";
    editor.undo();
    editor.display();

    cout << "--- Pressing Undo Again --- \n";
    editor.undo();
    editor.display();

    return 0;
}
