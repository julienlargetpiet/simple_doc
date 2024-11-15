#include <iostream>
#include <fstream>
#include <vector>

int main() {
  std::string title;
  std::cout << "Title: ";
  std::cin >> title;
  std::string t_str;
  std::cout << "File: ";
  std::string file;
  std::cin >> file;
  std::string logo = "";
  std::vector<std::string> mvec;
  std::cout << "Full path of the logo image if exists (\'N\' if it does not): ";
  std::cin >> logo;
  std::fstream myfile(file);
  std::string currow;
  std::string cur_doc;
  std::vector<std::string> fun_tocv;
  std::vector<int> depth_tocv;
  std::vector<bool> bool_tocv;
  int cur_depth = 0;
  std::vector<std::string> scope_tocv;
  std::string cur_scope = "";
  cur_doc = "<!DOCTYPE html>\n<head>\n<title>Documentation</title>\n";
  mvec.push_back(cur_doc);
  cur_doc = "<style>table { font-family: arial, sans-serif; border-collapse: collapse; width: 50%; }\n td, th { border: 1px solid #dddddd; text-algn: left; padding: 8px; }\n code { font-family: Consolas, \"courrier new\"; color: #ac3a3a; padding: 2px; }\n div.Div { border: 1px solid black; background-color: #f1f1f1; text-align: left; width: 500px; margin-left: 20px; }\n hr.hr { border: dotted 2px; }\n div.Div2 { background-color: #2c4786; text-align: center; width: 100%; padding: 0px 0px; margin: 0; color: white; top: 0px; font-size: 25px; }\n </style>\n";
  cur_doc += "</head>\n";
  cur_doc += "<body>\n";
  mvec.push_back(cur_doc);
  bool logo_bool = 0;
  if (logo != "N") {
    cur_doc = "<center><img src =\"" + logo + "\" width=250 height=100></center>\n";
    mvec.push_back(cur_doc);
    logo_bool = 1;
  };
  std::string folder = " ";
  int i;
  int n;
  bool D = 0;
  bool A = 0;
  bool E = 0;
  bool U = 0;
  bool I = 0;
  while (getline(myfile, currow)) {
    n = currow.length();
    if (n > 3) {
      if (currow[2] == '@') {
        if (currow[3] == 'I') {
            if (!I) {
              cur_doc = "<br><hr><h1><b id=\"INTRODUCTION\">INTRODUCTION:</b></h1>\n<p>";
              fun_tocv.push_back("INTRODUCTION");
              bool_tocv.push_back(0);
              depth_tocv.push_back(-1);
              scope_tocv.push_back("NOTHING");
              I = 1;
            } else {
              cur_doc = "<p>";
            };
            for (i = 5; i < n; ++i) {
              cur_doc += currow[i];
            };
            cur_doc += "</p>";
            mvec.push_back(cur_doc);
        } else if (currow[3] == 'T') {
            cur_doc = "";
            for (i = 5; i < n; ++i) {
              cur_doc += currow[i];
            };
            depth_tocv.push_back(cur_depth);
            bool_tocv.push_back(0);
            fun_tocv.push_back(cur_doc);
            scope_tocv.push_back(cur_scope);
            cur_doc = "<h2 id=\"" + cur_doc + "\" style=\"test-align: left;\">" + cur_doc + "</h2>\n";
            mvec.push_back(cur_doc);
        } else if (currow[3] == 'U') {
            if (!U) {
              cur_doc = "<h3>#Usage</h3>\n<div class=\"Div\"><code>";
              U = 1;
            } else {
              cur_doc = "<br>";
            };
            for (i = 5; i < n; ++i) {
              cur_doc += currow[i];
            };
          mvec.push_back(cur_doc);
        } else if (currow[3] == 'D') {
            if (!D) {
              D = 1;
              cur_doc = "<h3>#Description</h3>\n<p>";
            } else {
              cur_doc = "<p>";
            };
            for (i = 5; i < n; ++i) {
              cur_doc += currow[i];
            };
            cur_doc += "</p>\n";
            mvec.push_back(cur_doc);
        } else if (currow[3] == 'A') {
            if (!A) {
              cur_doc = "<h3>#Arguments</h3>\n<table><tr><th>Name</th><th>Definition</th></tr><tr><th>\n";
              A = 1;
              D = 0;
            } else {
              cur_doc = "<tr><th>";
            };
            for (i = 5; i < n; ++i) {
              if (currow[i] == ':') {
                cur_doc += "</th><th>";
              } else {
                cur_doc += currow[i];
              };
            };
          cur_doc += "</th></tr>\n";
          mvec.push_back(cur_doc);
        } else if (currow[3] == 'E') {
            if (!E) {
              cur_doc = "<h3>#Example(s)</h3>\n<div class = \"Div\"><code>";
              E = 1;
            } else {
              cur_doc = "<br><code>";
            };
            for (i = 5; i < n; ++i) {
              cur_doc += currow[i];
            };
            cur_doc += "</code>\n";
            mvec.push_back(cur_doc);
        } else if (currow[3] == 'X') {
            if (A) {
              cur_doc = "</table>\n<br>\n";
              A = 0;
            } else if (E) {
               cur_doc = "</div>\n<br>\n<hr class=\"hr\">\n";
               E = 0;
            } else if (U) {
               cur_doc = "</code></div>\n";
               U = 0;
            } else if (I) {
                cur_doc = "<br>\n<hr>\n";
                I = 0;
            };
            mvec.push_back(cur_doc);
        } else if (currow[3] == 'L') {
            cur_depth = int(currow[4]) - 48;
            if (cur_depth < 1) {
              cur_depth = 1;
            } else if (cur_depth > 6) {
              cur_depth = 6;
            };
            t_str = std::to_string(cur_depth);
            cur_doc = "<h" + t_str;
            cur_doc += " style=\"color:#2c4786;\">";
            cur_scope = "";
            for (i = 6; i < n; ++i) {
              cur_scope += currow[i];
            };
            scope_tocv.push_back(cur_scope);
            fun_tocv.push_back("X");
            depth_tocv.push_back(cur_depth);
            bool_tocv.push_back(1);
            cur_doc += cur_scope;
            cur_doc += "</h" + t_str;
            cur_doc += ">\n";
            mvec.push_back(cur_doc);
        } else if (currow[3] == 'J') {
            cur_depth = int(currow[4]) - 48;
            if (cur_depth < 0) {
              cur_depth = 0;
            } else if (cur_depth > 6) {
              cur_depth = 6;
            };
        } else if (currow[3] == 'F') {
            cur_doc = "";
            for (i = 5; i < n; ++i) {
              if (currow[i] != ' ') {
                cur_doc += currow[i];
              };
            };
            folder = cur_doc;
        } else if (currow[3] == 'M') {
            if (folder != " ") {
              cur_doc = "<br>\n<img style=\"margin-left: 20px;\" height=\"220\" width=\"360\" src=\"" + folder + "/";
            } else {
              cur_doc = "<br>\n<img style=\"margin-left: 20px;\" height=\"220\" width=\"360\" src=\"";
            };
            for (i = 5; i < n; ++i) {
              if (currow[i] != ' ') {
                cur_doc += currow[i];
              };
            };
            cur_doc += "\"><br>";
            mvec.push_back(cur_doc);
        } else if (currow[3] == 'V') {
            if (folder != " "){
              cur_doc = "<br><video style=\"margin-left: 20px;\" height=\"220\" width=\"360\" controls>\n<source src = \"" + folder + "/";
            } else {
              cur_doc = "<br><video style=\"margin-left: 20px;\" height=\"220\" width=\"360\" controls>\n<source src = \"";
            };
            for (i = 5; i < n; ++i) {
              if (currow[i] != ' ') {
                cur_doc += currow[i];
              };
            };
            cur_doc += "\">\n</video><br>";
            mvec.push_back(cur_doc);
        } else if (currow[3] == 'O') {
            if (folder != " "){
              cur_doc = "<br><br><audio style=\"margin-left: 20px;\" height=\"220\" width=\"360\" controls>\n<source src = \"" + folder + "/";
            } else {
              cur_doc = "<br><br><audio style=\"margin-left: 20px;\" height=\"220\" width=\"360\" controls>\n<source src = \"";
            };
            for (i = 5; i < n; ++i) {
              if (currow[i] != ' ') {
                cur_doc += currow[i];
              };
            };
            cur_doc += "\">\n</audio><br>";
            mvec.push_back(cur_doc);
        } else if (currow[3] == 'G') {
          t_str = currow[4];
          cur_doc = "<h" + t_str + ">";
          for (i = 6; i < n; ++i) {
            cur_doc += currow[i];
          };
          cur_doc += "</h" + t_str + ">";
          mvec.push_back(cur_doc);
        };
      };
    };
  };
  mvec.push_back("</body>\n\n");
  myfile.close();
  std::fstream outfile("out.html", std::ios::out);
  const int sizen = mvec.size();
  const int n2 = scope_tocv.size();
  int cnt = 0;
  if (logo_bool) {
    for (i = 0; i < sizen; ++i) {
      if (i == 2) {
        outfile << "<div class=\"Div2\"><i><b>" + title + "</b></i></div><br>";
      };
      if (i == 3) {
        outfile << "<div class=\"Div\"><a><i>Tabel Of Contents</i></a><br><br><ul>\n";
        for (cnt = 0; cnt < n2; ++cnt) {
          if (bool_tocv[cnt] != 0) {
            outfile << "<b><li style=\"margin-left:" + std::to_string(20 * depth_tocv[cnt]) + "px; color: #2c4786;\">" + scope_tocv[cnt] + "</li></b>\n";
          };
          if (fun_tocv[cnt] != "X") {
            outfile << "<a href=\"#" + fun_tocv[cnt] + "\" style=\"margin-left:" + std::to_string(20 + 20 * depth_tocv[cnt]) + "px;\">" + fun_tocv[cnt] + "</a>\n<br>\n";
          };
        };
        outfile << "</ul><br></div>\n";
      };
      outfile << mvec[i];
    };
  } else {
      for (i = 0; i < sizen; ++i) {
        //if (i == 1) {
        //  outfile << "<div class=\"Div2\"><i><b>" + title + "</b></i></div><br>";
        //};
        if (i == 2) {
          outfile << "<div class=\"Div2\"><i><b>" + title + "</b></i></div><br>";
          outfile << "<div class=\"Div\"><a><i>Tabel Of Contents</i></a><br><br><ul>\n";
          for (cnt = 0; cnt < n2; ++cnt) {
            if (bool_tocv[cnt] != 0) {
              outfile << "<b><li style=\"margin-left:" + std::to_string(20 * depth_tocv[cnt]) + "px; color: #2c4786;\">" + scope_tocv[cnt] + "</li></b>\n";
            };
            if (fun_tocv[cnt] != "X") {
              outfile << "<a href=\"#" + fun_tocv[cnt] + "\" style=\"margin-left:" + std::to_string(20 + 20 * depth_tocv[cnt]) + "px;\">" + fun_tocv[cnt] + "</a>\n<br>\n";
            };
          };
          outfile << "</ul><br></div>\n";
        };
        outfile << mvec[i];
      };
  };
  outfile.close();
  return 0;
};


