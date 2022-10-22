#include "Access.cpp"
void openFile()
{
    ifstream file("Access.txt");
    if (file.is_open())
    {
        string line;
        int i = 0;
        while (getline(file, line))
        {
            // insert data into array, split by comma
            istringstream iss(line);
            getline(iss, AccessPhone[i], ',');
            getline(iss, AccessPass[i], ',');
            getline(iss, AccessRole[i]);
            i++;
        }
    }
    file.close();
}
void saveFile()
{
    // save file
    ofstream myfile("Access.txt");
    for (int i = 0; i < maxrow; i++)
    {
        if (AccessPhone[i] == "\0")
        {
            break;
        }
        else
        {
            myfile << AccessPhone[i] << "," << AccessPass[i] << "," << AccessRole[i] << endl;
        }
    }
}
void Display()
{
    int count = 0;
    cout << "Here is the list: " << endl;
    printf("+---------------------------------------------------------------------+\n");
    printf("| %-12s | %-15s | %-10s |\n", "Phone", "Password", "Role");
    for (int i = 0; i < maxrow; i++)
    {
        if (AccessPhone[i] != "\0")
        {
            printf("| %-12s | %-15s | %-10s |", AccessPhone[i].c_str(), AccessPass[i].c_str(), AccessRole[i].c_str());
            cout << endl;
            count++;
        }
    }
    cout << "======================" << endl;
    cout << "Total records: " << count << endl;
    if (count == 0)
    {
        cout << "==> No records found" << endl;
    }
}