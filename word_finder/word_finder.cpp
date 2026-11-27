#include <iostream>
#include <vector>
#include <string>


std::string get_row(int n, const std::vector<std::string>& grid){
    std::string row;
    for (int i = 0; i < grid[0].size(); i++){
        row.push_back(grid[n][i]);
    }

    return row;
}

std::string get_col(int n, const std::vector<std::string>& grid){
    std::string col;
    for (int i = 0; i < grid.size(); i++){
        col.push_back(grid[i][n]);
    }

    return col;
}

std::string find_word(std::string target, std::string phrase, std::vector<std::string>& found){
    std::string out_phrase;
    int char_to_check = 0;

    for (int i = 0; i < phrase.size(); i++){
        if ((phrase[i] == target[char_to_check]) && (char_to_check < target.size())){
            out_phrase.push_back('*');
            char_to_check++;
        }
        else{
            out_phrase.push_back(phrase[i]);
        }
    }
    if (char_to_check == target.size()){    // a word has been found
        found.push_back(target);
        return out_phrase;
    }
    if (char_to_check == 0){    // if word isnt found
        for (int i = 0; i < found.size(); i++){
            if (found[i] == target){
                return phrase;
            }
        }
    }
    return phrase;

}

std::vector<std::string> col_transpose(const std::vector<std::string>& cols){
    std::vector<std::string> rows;
    for (int i = 0; i < cols[0].size(); i++){   // iterate through each column
        std::string row;

        for (int j = 0; j < cols.size(); j++){  // iterate through each row
            row.push_back(cols[j][i]);
        }

        rows.push_back(row);
    }

    return rows;
}

std::vector<std::string> grid_union(const std::vector<std::string>& v1, const std::vector<std::string>& v2){
    std::vector<std::string> vout = v1;
    for (int i = 0; i < vout.size(); i++){
        for (int j = 0; j < vout[0].size(); j++){
            if ((v1[i][j] == '*') || (v2[i][j] == '*')){
                vout[i][j] = '*';
            }
        }
    }

    return vout;
}

void find_words(
    const std::vector<std::string>& grid, 
    const std::vector<std::string>& words,
    std::vector<std::string>& solution,
    std::vector<std::string>& not_found
){
    // the idea is to iterate accross rows and columns. 
    // Create a copy of the grid for the rows iteration. a found word has a 1 in it. not found has a 0.
    // Repeat for the columns then take their union.
    // Then match the new grid of 0s and 1s with the origional. If 0, replace with #. If 1, replace with original character

    std::vector<std::string> rowmap = grid; // initialising them both to grid
    std::vector<std::string> colmap = grid;
    std::vector<std::string> unitedmap = grid;

    std::vector<std::string> found; // the words that have been found

    for (int w = 0; w < words.size(); w++){  // iterate through each word
        std::vector<std::string> tmp;
        for (int i = 0; i < grid.size(); i++){  // iterate through each row
            std::string mapped_row = find_word(words[w], get_row(i, grid), found);
            tmp.push_back(mapped_row);
        }

        rowmap = grid_union(tmp, rowmap);
        tmp.clear();

        for (int i = 0; i < grid[0].size(); i++){   // iterate through each column
            std::string mapped_col = find_word(words[w], get_col(i, grid), found);
            tmp.push_back(mapped_col);
        }

        tmp = col_transpose(tmp);
        colmap = grid_union(tmp, colmap);

    }

    unitedmap = grid_union(colmap, rowmap); // provides a map of where each word is with a * representing a character found
    
    std::vector<std::string> newgrid;
    for (int i = 0; i < unitedmap.size(); i++){
        std::string row;
        for (int j = 0; j < unitedmap[0].size(); j++){
            if (unitedmap[i][j] == '*'){
                row.push_back(grid[i][j]);
            }
            else{
                row.push_back('#');
            }
        }
        newgrid.push_back(row);
    }

    solution = newgrid;

    std::vector<std::string> not_fully_found; 
    for (int i = 0; i < words.size(); i++){     // iterating through each target word
        bool flag = 0;  // flag to see if 
        for (int j = 0; j < found.size(); j++){ // iterating through each word thats been found
            if (words[i] == found[j]){
                flag = 1;   // the word has been found
            }
        }

        if (!flag){
            not_fully_found.push_back(words[i]);
        }
    }

    not_found = not_fully_found;
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