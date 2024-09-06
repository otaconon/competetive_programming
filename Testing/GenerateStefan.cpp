#include <bits/stdc++.h>

#include <fstream>
#include <filesystem>  // For filesystem library
#include <string>

namespace fs = std::filesystem;

int main() {
    std::string directoryPath = "stefan_tests";

    if (!fs::exists(directoryPath)) {
        if (fs::create_directory(directoryPath)) {
            fs::create_directory(directoryPath + "/in");
            fs::create_directory(directoryPath + "/out");
            std::cout << "Directory created successfully: " << directoryPath << std::endl;
        } else {
            std::cerr << "Failed to create directory: " << directoryPath << std::endl;
            return 1;
        }
    } else {
        std::cout << "Directory already exists: " << directoryPath << std::endl;
    }

    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distr(-10, 10);

    for (int i = 0; i < 100; i++) {
        std::string inputFilePath = directoryPath + "/in/test" + std::to_string(i) + ".in";

        std::vector<int> nums;
        for (int i = 0; i < 10; i++) {
            int random_number = distr(gen);
            nums.push_back(random_number);
        }

        std::ofstream inFile(inputFilePath);
        if (!inFile.is_open()) {
            std::cerr << "Failed to create or open the file: " << inputFilePath << std::endl;
            return 1;
        }

        inFile << 10 << '\n';
        for (auto& num : nums) {
            inFile << num << ' ';
        }

        inFile.close();

        std::vector<int> p(11);
        p[0] = 0;
        for (int i = 1; i <= 10; i++) {
            p[i] = p[i-1] + nums[i-1];
        }

        int ans = 0;
        for (int i = 1; i <= 10; i++) {
            for (int j = i; j <= 10; j++) {
                ans = std::max(ans, p[j] - p[i-1]);
            }
        }

        std::string outputFilePath = directoryPath + "/out/test" + std::to_string(i) + ".out";

        std::ofstream outFile(outputFilePath);
        if (!outFile.is_open()) {
            std::cerr << "Failed to create or open the file: " << outputFilePath << std::endl;
            return 1;
        }

        outFile << ans << '\n';

        outFile.close();
    }

    return 0;
}