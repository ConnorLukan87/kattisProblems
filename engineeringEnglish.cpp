bool adjust_list(std::string word, std::vector<std::string>& haves) {
    // change the word to lower case
    std::locale loc; std::string lowered_word = "";
    for (std::string::size_type i = 0; i<word.length(); ++i) {
        lowered_word += std::tolower(word[i],loc);
    }
    for (std::string& k : haves) {
        if (lowered_word==k) {
            return false;
        }
    }

    haves.push_back(lowered_word);
    return true;
}

int main() {
    std::vector<std::string> haves;
    do {
        std::string temp; std::cin >> temp;
        std::string var = (adjust_list(temp, haves)) ? temp : ".";
        std::cout << var << " ";
    } while (!std::cin.eof());
    return 0;
}
