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
  std::string theme_file;
  std::cout << "Full path of the theme file (\'D\' for default): ";
  std::cin >> theme_file; 
  std::string background_color = "#FFFFFF";
  std::string top_color = "#2c4786";
  std::string titles_color = "#2c4786";
  std::string code_color = "#ac3a3a";
  std::string font_color = "#000000";
  std::string Title_color = "#FFFFFF";
  std::string code_background_color = "#f1f1f1";
  std::string toc_background_color = "#f1f1f1";
  std::string doc_background_color = "#f1f1f1";
  std::string font = "Times New Roman";
  unsigned int n;
  unsigned int i;
  std::string currow;
  if (theme_file != "D") {
   std::string cur_var;
    std::fstream theme_File(theme_file);
    std::string val_colfnt;
    bool cur_val;
    while (getline(theme_File, currow)) {
      val_colfnt = "";
      n = currow.length();
      cur_val = 0;
      i = 0;
      cur_var = "";
      if (currow.length() > 7) {
        while (!cur_val) {
          cur_var += currow[i];
          if (cur_var == "background_color") {
            cur_val = 1;
            i += 3;
            while (i < n) {
              val_colfnt += currow[i];
              i += 1;
            };
            background_color = val_colfnt;
          } else if (cur_var == "top_color") {
            cur_val = 1;
            i += 3;
            while (i < n) {
              val_colfnt += currow[i];
              i += 1;
            };
            top_color = val_colfnt;
          } else if (cur_var == "titles_color") {
            cur_val = 1;
            i += 3;
            while (i < n) {
              val_colfnt += currow[i];
              i += 1;
            };
            titles_color = val_colfnt;
          } else if (cur_var == "code_color") {
            cur_val = 1;
            i += 3;
            while (i < n) {
              val_colfnt += currow[i];
              i += 1;
            };
            code_color = val_colfnt;
          } else if (cur_var == "font_color") {
            cur_val = 1;
            i += 3;
            while (i < n) {
              val_colfnt += currow[i];
              i += 1;
            };
            font_color = val_colfnt;
          } else if (cur_var == "Title_color") {
            cur_val = 1;
            i += 3;
            while (i < n) {
              val_colfnt += currow[i];
              i += 1;
            };
            Title_color = val_colfnt;
          } else if (cur_var == "font" & currow[i + 1] == ':') {
            cur_val = 1;
            i += 3;
            while (i < n) {
              val_colfnt += currow[i];
              i += 1;
            };
            font = val_colfnt;
          } else if (cur_var == "code_background_color") {
            cur_val = 1;
            i += 3;
            while (i < n) {
              val_colfnt += currow[i];
              i += 1;
            };
            code_background_color = val_colfnt;
          } else if (cur_var == "toc_background_color") {
            cur_val = 1;
            i += 3;
            while (i < n) {
              val_colfnt += currow[i];
              i += 1;
            };
            toc_background_color = val_colfnt;
          } else if (cur_var == "doc_background_color") {
            cur_val = 1;
            i += 3;
            while (i < n) {
              val_colfnt += currow[i];
              i += 1;
            };
            doc_background_color = val_colfnt;
          };
          i += 1;
        };
      };
    };
  };
  std::fstream myfile(file);
  std::string cur_doc;
  std::vector<std::string> fun_tocv;
  std::vector<int> depth_tocv;
  std::vector<bool> bool_tocv;
  int cur_depth = 0;
  std::vector<std::string> scope_tocv;
  std::string cur_scope = "";
  cur_doc = "<!DOCTYPE html>\n<head>\n<title>" + title + "</title>\n";
  mvec.push_back(cur_doc);
  cur_doc = "<style>\ntable { border-collapse: collapse;\n width: 50%; }\n\ntd, th { border: 1px solid #dddddd;\n text-algn: left;\n padding: 8px; }\n\ncode { font-family: Consolas, \"courrier new\";\n color: " + code_color + ";\n padding: 2px; }\n\ndiv.Div { border: 1px solid black;\n background-color:" + code_background_color + ";\n text-align: left;\n width: 500px;\n margin-left: 20px;\n border-radius: 10px;\n padding: 5px; }\n\nhr.hr { border: dotted 2px; }\n\ndiv.Div2 { background-color:" + top_color + ";\n text-align: center;\n width: 100%;\n padding: 0px 0px;\n margin: 0;\n color: " + Title_color + ";\n top: 0px;\n font-size: 25px; }\n\ndiv.container { display: flex;\n gap: 25px;\n align-items: flex-start;\n box-sizing: border-box; }\n\ndiv.box1{ border: 2px solid black;\n background-color:" + toc_background_color + ";\n border-radius: 10px;\n text-align: left;\n width: 500px;\n position: sticky;\n top: 0;\n height: auto;\n overflow: visible;\n padding: 10px; }\n\ndiv.box2 { border: 2px solid black;\n background-color: " + doc_background_color + ";\n width: 100%;\n margin-right: 25px;\n border-radius: 15px;\n padding: 10px;\n }\nbody { background-color: " + background_color +";\nfont-family:" + font + ", sans-serif; }\np { color:" + font_color + "; }\n</style>\n";
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
              cur_doc = "<br><hr><h1 style=\"color: " + titles_color + ";\"><b id=\"INTRODUCTION\">INTRODUCTION:</b></h1>\n<p>";
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
            cur_doc += " style=\"color:" + titles_color + ";\">";
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
          cur_doc = "<h" + t_str + " style=\"color: " + titles_color + ";\">";
          for (i = 6; i < n; ++i) {
            cur_doc += currow[i];
          };
          cur_doc += "</h" + t_str + ">";
          mvec.push_back(cur_doc);
        };
      };
    };
  };
  mvec.push_back("</div>\n</div>\n</body>\n\n");
  myfile.close();
  std::fstream outfile("out.html", std::ios::out);
  const unsigned int sizen = mvec.size();
  const unsigned int n2 = scope_tocv.size();
  unsigned int cnt = 0;
  if (logo_bool) {
    for (i = 0; i < sizen; ++i) {
      if (i == 2) {
        outfile << "<div class=\"Div2\"><i><b>" + title + "</b></i></div><br>";
      };
      if (i == 3) {
        outfile << "<div class=\"container\">\n<div class=\"box1\"><a><i>Table Of Contents</i></a><br><br><ul>\n";
        for (cnt = 0; cnt < n2; ++cnt) {
          if (bool_tocv[cnt] != 0) {
            outfile << "<b><li style=\"margin-left:" + std::to_string(20 * depth_tocv[cnt]) + "px; color: " + titles_color + ";\">" + scope_tocv[cnt] + "</li></b>\n";
          };
          if (fun_tocv[cnt] != "X") {
            outfile << "<a href=\"#" + fun_tocv[cnt] + "\" style=\"margin-left:" + std::to_string(20 + 20 * depth_tocv[cnt]) + "px;\">" + fun_tocv[cnt] + "</a>\n<br>\n";
          };
        };
        outfile << "</ul><br></div>\n<div class=\"box2\">\n";
      };
      outfile << mvec[i];
    };
  } else {
      for (i = 0; i < sizen; ++i) {
        if (i == 2) {
          outfile << "<div class=\"Div2\"><i><b>" + title + "</b></i></div><br>";
          outfile << "<div class=\"container\">\n<div class=\"box1\"><a><i>Table Of Contents</i></a><br><br><ul>\n";
          for (cnt = 0; cnt < n2; ++cnt) {
            if (bool_tocv[cnt] != 0) {
              outfile << "<b><li style=\"margin-left:" + std::to_string(20 * depth_tocv[cnt]) + "px; color:" + titles_color + ";\">" + scope_tocv[cnt] + "</li></b>\n";
            };
            if (fun_tocv[cnt] != "X") {
              outfile << "<a href=\"#" + fun_tocv[cnt] + "\" style=\"margin-left:" + std::to_string(20 + 20 * depth_tocv[cnt]) + "px;\">" + fun_tocv[cnt] + "</a>\n<br>\n";
            };
          };
          outfile << "</ul><br></div>\n<div class=\"box2\">\n";
        };
        outfile << mvec[i];
      };
  };
  outfile.close();
  return 0;
};


