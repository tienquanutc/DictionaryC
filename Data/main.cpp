#include <fstream>

using namespace std;


int main(int argc, char const *argv[]) {
    fstream f;
    f.open("./data.txt", ios_base::out);

    const int n  = 50;

    for(int i = 0; i < n; ++i){
        f << "eng " << i << endl;
        f << "envi " << i << endl;
    }

    return 0;
}
