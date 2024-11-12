#include <iostream>
#include <fstream>

int main() {
  std::cout << "File: ";
  std::string file;
  std::cin >> file;
  std::string logo;
  std::cout << "Path of the logo image if exists: ";
  std::cin >> logo;
  std::fstream myfile(file);
  std::fstream outfile("out.html", std::ios::out);
  outfile << "<!DOCTYPE html>\n<head>\n<title>Documentation</title>\n</head>\n";
  outfile << "<body>\n";
  if (logo.length() > 0) {
    outfile << "<img src =\"" << logo << "\" width=250 height=100>\n";
  };
  std::string currow;
  std::string cur_doc;
  int i;
  int n;
  bool D = 0;
  bool A = 0;
  bool E = 0;
  while (getline(myfile, currow)) {
    n = currow.length();
    if (n > 3) {
      if (currow[2] == '@') {
        if (currow[3] == 'T') {
            cur_doc = "<h2>";
            for (i = 4; i < n; ++i) {
              cur_doc += currow[i];
            };
            outfile << cur_doc << "</h2>\n";
        } else if (currow[3] == 'U') {
            cur_doc = "<h3>#Usage</h3><code>";
            for (i = 4; i < n; ++i) {
              cur_doc += currow[i];
            };
          outfile << cur_doc << "</code><br>\n";
        } else if (currow[3] == 'D') {
            if (!D) {
              D = 1;
              cur_doc = "<h3>#Description</h3><p>";
            } else {
              cur_doc = "<p>";
            };
            for (i = 4; i < n; ++i) {
              cur_doc += currow[i];
            };
            outfile << cur_doc << "</p>\n";
        } else if (currow[3] == 'A') {
            if (!A) {
              outfile << "<h3>#Arguments</h3><table><tr><th>Name</th><th>Definition</th></tr>\n";
              A = 1;
              D = 0;
            };
            cur_doc = "<tr><th>";
            for (i = 4; i < n; ++i) {
              if (currow[i] == ':') {
                cur_doc += "</th><th>";
              } else {
                cur_doc += currow[i];
              };
            };
            outfile << cur_doc << "</th></tr>\n";
        } else if (currow[3] == 'E') {
            if (!E) {
              cur_doc = "<h3>#Example(s)</h3><code>";
              E = 1;
            } else {
              cur_doc = "";
            };
            for (i = 4; i < n; ++i) {
              cur_doc += currow[i];
            };
            outfile << cur_doc << "<br>\n";
        } else if (currow[3] == 'X') {
            if (A) {
              outfile << "</table><br>\n";
              A = 0;
            } else if (E) {
              outfile << "</code><br>\n"; 
              E = 0;
            };
        } else if (currow[3] == 'L') {
            cur_doc = "<h1>";
            for (i = 4; i < n; ++i) {
              cur_doc += currow[i];
            };
            outfile << cur_doc << "</h1>\n";
        };
      };
    };
  };
  outfile << "</body>\n\n";
  myfile.close();
  outfile.close();
  return 0;
};


