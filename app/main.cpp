/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <string.h>
#include <cstring>

#include <cxxopts.hpp>
#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

#include "config.hpp"
#include "func.h"

using namespace std; 

int main() {
    string transmission1File = "../transmission1.txt";
    string transmission2File = "../transmission2.txt";
    string mcode1File = "../mcode1.txt";
    string mcode2File = "../mcode2.txt";
    string mcode3File = "../mcode3.txt";

    vector<string> transmissionFiles = {transmission1File, transmission2File};
    vector<string> codeFiles = {mcode1File, mcode2File, mcode3File};
    
    // Part 1
    for (int i = 0; i < transmissionFiles.size(); i++){
        for (int j = 0; j < codeFiles.size(); j++){
            int index = containsCode(transmissionFiles[i], codeFiles[j]);
            if (index == -1){
                cout << "false" << endl;
            } else {
                cout << "true" << " " << index << endl;
            }

        }
    }

    // Part 2
    for (int i = 0; i < transmissionFiles.size(); i++){
        tuple<int, int, string> result = findLongestPalindrome(transmissionFiles[i]);
        int startIndex = get<0>(result);
        int endIndex = get<1>(result);
        string longestPalindrome = get<2>(result);
        cout << startIndex << " " << endIndex << " " << longestPalindrome << endl;
    }

    // Part 3
    cout<<endl<<"part3:"<<endl;
    tuple<int, int, string> longestCommonSubstring = findLongestCommonSubstring(transmission1File, transmission2File);
    cout << endl<<get<0>(longestCommonSubstring)<<endl<<get<1>(longestCommonSubstring)<<endl<<get<2>(longestCommonSubstring)<<endl;

    return 0;
}
