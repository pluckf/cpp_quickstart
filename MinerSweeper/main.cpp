// #include <iostream>
// #include <vector>

// #include <ctime>
// using namespace std;
// void front_message(){

    
// }


// void set_miner(vector<vector<char>>& real_board, int num_mines) {
//     int count = 0;
//     while (count < num_mines) {
//         int x = rand() % 10;
//         int y = rand() % 10;
//         if (real_board[x][y] != '*') {
//             real_board[x][y] = '*';
//             count++;
//         }
//     }
// }
// void show_board(const vector<vector<char>>& board) {
//     for (const auto& row : board) {
//         for (const auto& cell : row) {
//             cout << cell << ' ';
//         }
//         cout << endl;
//     }
// }
// void click_board(vector<vector<char>>& player_board,vector<vector<char>>& real_board,int x, int y) {
//     player_board[x][y] = 'O';
// }
// void check_miner_and_refresh(const vector<vector<char>>& real_board,int x, int y, vector<vector<char>>& player_board,bool& refresh) {
//         if(refresh){
//         int miner_count = 0;
//         for (int dx = -1; dx <= 1; dx++) {
//             for (int dy = -1; dy <= 1; dy++) {
//                 if (dx == 0 && dy == 0) continue;
//                 int nx = x + dx;
//                 int ny = y + dy;
//                 // 只有坐标在有效范围内才访问
//                 if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
//                     if (real_board[nx][ny] == '*') {
//                         miner_count++;
//                         refresh=false;
//                     } 
//                     else player_board[nx][ny] = 'O';

//                 }
//                 }
//             }
//             if(miner_count) player_board[x][y] = miner_count+'0'; 
//             else{
//             for (int dx = -1; dx <= 1; ++dx) {
//             for (int dy = -1; dy <= 1; ++dy) {
//                 if (dx == 0 && dy == 0) continue;
//                 check_miner_and_refresh(real_board,x+dx,y+dy,player_board, refresh);

//             }
//             }}
//         }
//         else {
//             return;}
        
        
//     }
    



// int main() {
//     srand(18);
//     int x, y;
//     vector<vector<char>> real_board(10, vector<char>(10, '#'));
//     set_miner(real_board, 5);
//     vector<vector<char>> player_board(10, vector<char>(10, '#'));
//     bool refresh = true;
//     while (true){
//         system("cls");
//         front_message();
//         show_board(real_board);
//         cout<<"--------------------"<<endl;
//         show_board(player_board);
//         cin >> x >> y; 
//         if(x < 0 || x >= 10 || y < 0 || y >= 10) {
//             cout << "Invalid coordinates. Please enter values between 0 and 9." << endl;
//             continue;
//         }
        
//         click_board(player_board, real_board, x, y);
//         check_miner_and_refresh(real_board,x,y,player_board, refresh);
        
        
//     }
//     return 0;
// }


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

// 棋盘大小和地雷数量
constexpr int BOARD_SIZE = 10;
constexpr int MINES = 10;

// 跨平台清屏函数
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 设置控制台编码（仅 Windows 需要）
void setConsoleUTF8() {
#ifdef _WIN32
    system("chcp 65001 > nul");  // 切换到 UTF-8 代码页
#endif
}

// 延时函数（毫秒）
void delayMs(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// 在真实棋盘上随机布雷
void placeMines(vector<vector<char>>& realBoard) {
    int placed = 0;
    while (placed < MINES) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (realBoard[x][y] != '*') {
            realBoard[x][y] = '*';
            ++placed;
        }
    }
}

// 打印玩家看到的棋盘（带行列号）
void printBoard(const vector<vector<char>>& board) {
    // 打印列号
    cout << "  ";
    for (int j = 0; j < BOARD_SIZE; ++j)
        cout << j << ' ';
    cout << endl;

    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << i << ' ';   // 行号
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

// 递归展开空白格（Flood Fill）
void expandEmpty(vector<vector<char>>& playerBoard,
                 const vector<vector<char>>& realBoard,
                 int x, int y) {
    // 边界检查
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE)
        return;
    // 已翻开或标记为地雷的格子不处理
    if (playerBoard[x][y] != '#')
        return;

    // 计算周围地雷数量
    int mineCount = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE &&
                realBoard[nx][ny] == '*') {
                ++mineCount;
            }
        }
    }

    if (mineCount > 0) {
        // 有雷 → 显示数字
        playerBoard[x][y] = '0' + mineCount;
        return;
    }

    // 无雷 → 标记为空格（用 ' ' 表示）并递归展开所有邻居
    playerBoard[x][y] = ' ';
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            expandEmpty(playerBoard, realBoard, x + dx, y + dy);
        }
    }
}

// 检查是否胜利（所有非地雷格子都被翻开）
bool checkWin(const vector<vector<char>>& playerBoard,
              const vector<vector<char>>& realBoard) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (realBoard[i][j] != '*' && playerBoard[i][j] == '#')
                return false;   // 还有未翻开的非雷格子
        }
    }
    return true;
}

// 游戏结束：显示所有地雷位置（用于失败时展示）
void revealAllMines(vector<vector<char>>& playerBoard,
                    const vector<vector<char>>& realBoard) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (realBoard[i][j] == '*')
                playerBoard[i][j] = '*';
        }
    }
}

int main() {
    setConsoleUTF8();          // 设置 UTF-8 编码（Windows 下生效）
    srand(static_cast<unsigned>(time(nullptr)));

    // 初始化棋盘
    vector<vector<char>> realBoard(BOARD_SIZE, vector<char>(BOARD_SIZE, '#'));
    vector<vector<char>> playerBoard(BOARD_SIZE, vector<char>(BOARD_SIZE, '#'));

    placeMines(realBoard);

    int x, y;
    bool gameOver = false;

    while (!gameOver) {
        clearScreen();   // 清屏
        cout << "===== 扫雷 (" << BOARD_SIZE << "x" << BOARD_SIZE
             << ", 共 " << MINES << " 颗雷) =====" << endl;
        cout << "符号说明：# 未翻开  数字 周围雷数  空格 已翻开空白" << endl;
        cout << "输入行号和列号（空格分隔），例如: 3 5" << endl;
        cout << endl;
        printBoard(playerBoard);

        cout << "请输入坐标 (行 列): ";
        if (!(cin >> x >> y)) {
            // 输入非数字，清空错误状态并忽略本行
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "输入无效，请输入两个整数！" << endl;
            delayMs(1000);
            continue;
        }

        // 检查坐标合法性
        if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            cout << "坐标超出范围 (0~" << BOARD_SIZE - 1 << ")，请重新输入！" << endl;
            delayMs(1000);
            continue;
        }

        // 检查该格是否已翻开
        if (playerBoard[x][y] != '#') {
            cout << "该格子已翻开，请选择其他位置！" << endl;
            delayMs(1000);
            continue;
        }

        // 踩雷判断
        if (realBoard[x][y] == '*') {
            // 游戏失败：显示所有地雷
            revealAllMines(playerBoard, realBoard);
            clearScreen();
            cout << "===== 游戏结束 =====" << endl;
            printBoard(playerBoard);
            cout << "💥 踩到地雷了！游戏失败！" << endl;
            gameOver = true;
            break;
        }

        // 展开当前格子（自动递归展开空白区域）
        expandEmpty(playerBoard, realBoard, x, y);

        // 胜利检测
        if (checkWin(playerBoard, realBoard)) {
            clearScreen();
            cout << "===== 恭喜胜利 =====" << endl;
            printBoard(playerBoard);
            cout << "🎉 你翻开了所有非雷格子，赢了！" << endl;
            gameOver = true;
            break;
        }

        // 略微延迟，避免刷新过快（可自行调整）
        delayMs(100);
    }

    // 暂停，让玩家看到结果后按任意键退出
    cout << "\n按回车键退出..." << endl;
    cin.ignore();          // 清除输入缓冲区中的残留回车
    cin.get();             // 等待用户按回车
    return 0;
}
