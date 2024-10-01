#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool file_exists(const string& filename) {
    ifstream file(filename);
    return file.good();
}

void create_file_if_needed(ofstream& file) {
    file << "<!DOCTYPE html>\n"
         << "<html lang=\"en\">\n"
         << "<head>\n"
         << "    <meta charset=\"UTF-8\">\n"
         << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
         << "    <title>Document</title>\n"
         << "</head>\n"
         << "<body>\n"
         << "    <table border=\"1\">\n"
         << "        <tr>\n"
         << "            <th>User</th>\n"
         << "            <th>Password</th>\n"
         << "        </tr>\n";
}
vector<string> read_table(const string& filename) {
    vector<string> rows;
    string line;
    ifstream infile(filename);
    bool inside_table = false;
    
    while (getline(infile, line)) {
        if (line.find("<table") != string::npos) {
            inside_table = true;
        }
        else if (line.find("</table>") != string::npos) {
            inside_table = false;
        }
        else if (inside_table && line.find("<tr>") != string::npos) {
            string row;
            while (getline(infile, line) && line.find("</tr>") == string::npos) {
                row += line + "\n";
            }
            row += line + "\n"; // Add the closing </tr> tag
            rows.push_back(row);
        }
    }
    infile.close();
    return rows;
}

void write_table(const string& filename, const vector<string>& rows) {
    string line, content;
    ifstream infile(filename);
    bool inside_table = false;
    
    while (getline(infile, line)) {
        if (line.find("<table") != string::npos) {
            inside_table = true;
            content += line + "\n";  // Keep table header
        }
        else if (line.find("</table>") != string::npos) {
            inside_table = false;
            for (const auto& row : rows) {
                content += row;  // Add all rows before closing the table
            }
            content += line + "\n";  // Keep table footer
        }
        else if (!inside_table) {
            content += line + "\n";  // Keep content outside the table
        }
    }
    infile.close();
    
    // Write the content with updated rows back to the file
    ofstream outfile(filename);
    outfile << content;
    outfile.close();
}

void append_row(const string& filename, const string& user, const string& password) {
    vector<string> rows = read_table(filename);
    string new_row = "        <tr>\n"
                     "            <td>" + user + "</td>\n"
                     "            <td>" + password + "</td>\n"
                     "        </tr>\n";
    rows.push_back(new_row);
    write_table(filename, rows);
}

void close_file(ofstream& file) {
    file << "    </table>\n"
         << "</body>\n"
         << "</html>";
    file.close();
}

void clear_table(const string& filename) {
    string line, content;
    ifstream infile(filename);
    bool inside_table = false;
    
    while (getline(infile, line)) {
        if (line.find("<table") != string::npos) {
            inside_table = true;
            content += line + "\n";  // Keep table header
        }
        else if (line.find("</table>") != string::npos) {
            inside_table = false;
            content += line + "\n";  // Keep table footer
        }
        else if (!inside_table) {
            content += line + "\n";  // Keep content outside the table
        }
    }
    infile.close();
    
    // Write the cleaned content back to the file
    ofstream outfile(filename);
    outfile << content;
    outfile.close();
}



void edit_row(const string& filename, int row_index, const string& new_user, const string& new_password) {
    vector<string> rows = read_table(filename);
    if (row_index < 0 || row_index >= rows.size()) {
        cout << "Invalid row index." << endl;
        return;
    }
    rows[row_index] = "        <tr>\n"
                      "            <td>" + new_user + "</td>\n"
                      "            <td>" + new_password + "</td>\n"
                      "        </tr>\n";
    write_table(filename, rows);
}

void delete_row(const string& filename, int row_index) {
    vector<string> rows = read_table(filename);
    if (row_index < 0 || row_index >= rows.size()) {
        cout << "Invalid row index." << endl;
        return;
    }
    rows.erase(rows.begin() + row_index);
    write_table(filename, rows);
}

int main() {
    const string filename = "index.html";
    
    // Open the file in append mode if it exists, otherwise create it
    ofstream file;
    bool exists = file_exists(filename);
    
    if (!exists) {
        file.open(filename, ios::out);  // Create new file if doesn't exist
        create_file_if_needed(file);    // Write the initial structure
        close_file(file);               // Properly close file with ending tags
    }

    // Input from the user
    char option;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add a new row\n";
        cout << "2. Clear the table content\n";
        cout << "3. Edit a row\n";
        cout << "4. Delete a row\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case '1': {
                string user, password;
                cout << "Enter username: ";
                cin >> user;
                cout << "Enter password: ";
                cin >> password;
                append_row(filename, user, password);
                cout << "Row added successfully!" << endl;
                break;
            }
            case '2': {
                clear_table(filename);
                cout << "Table cleared successfully!" << endl;
                break;
            }
            case '3': {
                int row_index;
                string user, password;
                cout << "Enter row index to edit: ";
                cin >> row_index;
                cout << "Enter new username: ";
                cin >> user;
                cout << "Enter new password: ";
                cin >> password;
                edit_row(filename, row_index, user, password);
                cout << "Row edited successfully!" << endl;
                break;
            }
            case '4': {
                int row_index;
                cout << "Enter row index to delete: ";
                cin >> row_index;
                delete_row(filename, row_index);
                cout << "Row deleted successfully!" << endl;
                break;
            }
            case '5': {
                cout << "Exiting program..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (option != '5');

    return 0;
}
