#include <iostream>
#include <vector>
#include <string>


std::vector<int> find_word_in_phrase(const std::string& target, const std::string& phrase){ 
    // a function using a FSM to search for word. 
    // Returns a vector of the start positions of found words
    int state = 0;
    std::vector<int> word_indexs;

    for (int i = 0; i < phrase.size(); i++){
        if (phrase[i] == target[state]){
            state++;
            if (state == target.size()){
                for (int j = (i - target.size() + 1); j <= i; j++)
                word_indexs.push_back(j);
            }
        }
        else{
            i = i - state;
            state = 0;  // reset the state
        }
    }

    return word_indexs;
}

std::string get_col(int n, const std::vector<std::string>& grid){
    std::string col;
    for (int i = 0; i < grid.size(); i++){
        col.push_back(grid[i][n]);
    }

    return col;
}

bool contains(const std::string& element, const std::vector<std::string> v){
    for (int i = 0; i < v.size(); i++){
        if (v[i] == element){
            return 1;
        }
    }

    return 0;
}

void find_words(
    const std::vector<std::string>& grid, 
    const std::vector<std::string>& words,
    std::vector<std::string>& solution,
    std::vector<std::string>& not_found
){

    std::vector<std::string> outgrid;
    std::vector<int> word_indexs;
    std::vector<std::string> found;

    for (int i = 0; i < grid.size(); i++){  // initialise an empty solution grid of all #s
        std::string row;
        for (int j = 0; j < grid[0].size(); j++){
            row.push_back('#');
        }
        outgrid.push_back(row);
    }

    for (int w = 0; w < words.size(); w++){

        for (int r = 0; r < grid.size(); r++){  // rows
            word_indexs.clear();
            word_indexs = find_word_in_phrase(words[w], grid[r]);

            if (word_indexs.size() && !contains(words[w], found)){
                found.push_back(words[w]);
            }

            for (int i = 0; i < word_indexs.size(); i++){
                outgrid[r][word_indexs[i]] = grid[r][word_indexs[i]];
            }

        }

        for (int c = 0; c < grid[0].size(); c++){
            std::string col = get_col(c, grid);

            word_indexs.clear();
            word_indexs = find_word_in_phrase(words[w], col);

            if (word_indexs.size() && !contains(words[w], found)){
                found.push_back(words[w]);
            }

            // std::cout <<"Looking for " << words[w] << " in " << col << " " << word_indexs.size() << std::endl;

            for (int i = 0; i < word_indexs.size(); i++){
                outgrid[word_indexs[i]][c] = grid[word_indexs[i]][c];
            }
        }

    }

    solution = outgrid;

    for (int i = 0; i < words.size(); i++){
        if (!contains(words[i], found)){
            not_found.push_back(words[i]);
        }
    }
}


int main(){

    std::vector<std::string> grid = {
        "xappleg",
        "dzeazkg",
        "zwazzbx",
        "dxnqzoy",
        "qyueytp",
        "pythtyg"
    };

    std::vector<std::string> words = {"peanut", "bot", "mango", "apple", "cinnamon"};
    std::vector<std::string> solution;
    std::vector<std::string> not_found;

    find_words(grid, words, solution, not_found); 

    std::vector<std::string> expected_solution = {
        "#apple#",
        "##e####",
        "##a##b#",
        "##n##o#",
        "##u##t#",
        "##t####"
    };

    std::vector<std::string> expected_not_found = {"mango", "cinnamon"};

    if( (solution == expected_solution) && (not_found == expected_not_found) ){
        std::cout << "test passed" << std::endl;
    }
    else{
        std::cout << "test failed" << std::endl;
    }

    std::cout << "solution:" << std::endl;
    for(int i = 0; i < solution.size(); i++){
        std::cout << solution[i] << std::endl;
    }

    std::cout << "not found:" << std::endl;
    for(int i = 0; i < not_found.size(); i++){
        std::cout << not_found[i] << std::endl;
    }
}