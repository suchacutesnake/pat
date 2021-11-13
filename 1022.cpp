//1022 Digital Library (30 point(s))
//Notice that the output ID has 7 digits. If you stores id with int,
//remember to use %07d for output
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
class Books {
public:
    std::string ID;
    std::string book_title;
    std::string author;
    std::string keywords[5];
    std::string publisher;
    std::string published_year;
    void process_book(std::vector<std::unordered_map<std::string, std::vector<int> > >& query, int& i) {
        query[1][book_title].push_back(i);
        query[2][author].push_back(i);
        for (int j = 0; j < 5; ++j) query[3][keywords[j]].push_back(i);
        query[4][publisher].push_back(i);
        query[5][published_year].push_back(i);
    }
};
int main() {
    int N, M;
    std::cin >> N;
    
    std::vector<Books> book_list(N);
    std::vector<std::unordered_map<std::string, std::vector<int> > > query(6);
    for (int i = 0; i < N; ++i) {
        scanf("\n");
        Books& book = book_list[i];
        std::getline(std::cin, book.ID);
        std::getline(std::cin, book.book_title);
        std::getline(std::cin, book.author);
        int j = 0;
        while (std::cin >> book.keywords[j++]) {
            char c = getchar();
            if (c == '\n') break;
        }
        std::getline(std::cin, book.publisher);
        std::cin >> book.published_year;
        book.process_book(query, i);
    }
    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        int option;
        std::string content;
        scanf("%d: ", &option);
        std::getline(std::cin, content);
        std::cout << option << ": " << content << std::endl;
        if (query[option].count(content)) {
            std::vector<int>& output = query[option][content];
            std::vector<std::string> res;
            for (int& idx : output) res.push_back(book_list[idx].ID);
            sort(res.begin(), res.end());
            for (std::string& id : res) printf("%s\n", id.c_str());
        }
        else printf("Not Found\n");
    }
    return 0;
}