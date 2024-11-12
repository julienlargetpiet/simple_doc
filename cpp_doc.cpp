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
  outfile << "<!DOCTYPE html>\n<head>\n<title>Documentation</title>\n";
  outfile << "<style>table { font-family: arial, sans-serif; border-collapse: collapse; width: 50%; }\n td, th { border: 1px solid #dddddd; text-algn: left; padding: 8px; }\n code { font-family: Consolas, \"courrier new\"; color: #2555C8; padding: 2px; }\n div.Div { border: 1px solid black; background-color: #f1f1f1; text-align: left; max-width: 500px; margin-left: 20px; }\n </style>\n";
  outfile << "</head>\n";
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
            cur_doc = "<h3>#Usage</h3>\n<div class=\"Div\"><code>";
            for (i = 4; i < n; ++i) {
              cur_doc += currow[i];
            };
          outfile << cur_doc << "</code></div><br>\n";
        } else if (currow[3] == 'D') {
            if (!D) {
              D = 1;
              cur_doc = "<h3>#Description</h3>\n<p>";
            } else {
              cur_doc = "<p>";
            };
            for (i = 4; i < n; ++i) {
              cur_doc += currow[i];
            };
            outfile << cur_doc << "</p>\n";
        } else if (currow[3] == 'A') {
            if (!A) {
              outfile << "<h3>#Arguments</h3>\n<table><tr><th>Name</th><th>Definition</th></tr>\n";
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
              cur_doc = "<h3>#Example(s)</h3>\n<div class = \"Div\"><code>";
              E = 1;
            } else {
              cur_doc = "<br><code>";
            };
            for (i = 4; i < n; ++i) {
              cur_doc += currow[i];
            };
            outfile << cur_doc << "</code>\n";
        } else if (currow[3] == 'X') {
            if (A) {
              outfile << "</table><br>\n";
              A = 0;
            } else if (E) {
              outfile << "</div>\n"; 
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


