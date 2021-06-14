#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

#define CLEAR "\e[0m"

typedef struct GameField
{
  int row;
  int column;

  explicit GameField(const int newRow, const int newColumn)
  {
    row = newRow;
    column = newColumn;
  }
  GameField(const GameField &gameField)
  {
    row = gameField.row;
    column = gameField.column;
  }

  GameField(const GameField &&gameField)
  {
    row = gameField.row;
    column = gameField.column;
  }

  GameField()
  {
    row = 0;
    column = 0;
  }
} GameField;

const int rows = 9;
const int columns = 9;

bool validateInput(const string input)
{
  if (input.length() != 2)
    return false;

  if (input[0] < 97 || input[0] > 97 + columns - 1)
    return false;

  if (input[1] < 49 || input[1] > 49 + rows - 1)
    return false;

  return true;
}

void getInput(int *column, int *row)
{
  string input;
  cout << "Geben sie eine Spalte und eine Zeile ein (z.B.: b3)" << endl;

  do
  {
    getline(cin, input);
  } while (!validateInput(input));

  *column = input[0] - 97;
  *row = input[1] - 49;
}

bool isEmpty(const vector<vector<int>> board)
{
  for (int i = 0; i < board.size(); i++)
  {
    vector<int> row = board[i];
    for (int j = 0; j < row.size(); j++)
    {
      if (row[j] != 0)
        return false;
    }
  }

  return true;
}

void printBoard(const vector<vector<int>> board, const int score)
{
  cout << endl;
  cout << "Score: " << score << endl;
  cout << endl;

  for (int i = 0; i < board.size(); i++)
  {
    cout << i + 1 << " ";
    vector<int> row = board[i];
    for (int j = 0; j < row.size(); j++)
    {
      int color = row[j];
      cout << "\e[0;" << (color == 0 ? 30 : color) << "m"
           << "███";
    }
    cout << CLEAR << endl;
  }

  cout << "  ";
  for (int i = 0; i < board.size(); i++)
  {
    cout << " " << (char)(i + 97) << " ";
  }
  cout << endl;
}

bool moreMovesPossible(const vector<vector<int>> board)
{
  for (int i = 0; i < board.size() - 1; i++)
  {
    vector<int> row = board[i];
    for (int j = 0; j < row.size() - 1; j++)
    {
      int color = row[j];
      if (color == 0)
        continue;

      if (row[j + 1] == color || board[i + 1][j] == color)
        return true;
    }
  }

  return false;
}

bool isValidMove(const vector<vector<int>> board, const int column, const int row)
{
  int color = board[row][column];

  if (color == 0)
    return false;

  if (row != 0)
    if (board[row - 1][column] == color)
      return true;

  if (row != board.size() - 1)
    if (board[row + 1][column] == color)
      return true;

  if (column != 0)
    if (board[row][column - 1] == color)
      return true;

  if (column != board[0].size() - 1)
    if (board[row][column + 1] == color)
      return true;

  return false;
}

void getGroup(vector<vector<int>> *board, int column, int row, vector<GameField> *group)
{
  bool exists = false;
  for (int i = 0; i < group->size(); i++)
  {
    if (group->at(i).column == column && group->at(i).row == row)
      exists = true;
  }

  if (exists)
    return;

  GameField field(row, column);
  group->emplace_back(move(field));

  int color = board->at(row)[column];

  if (row != 0)
    if (board->at(row - 1)[column] == color)
      getGroup(board, column, row - 1, group);

  if (row != board->size() - 1)
    if (board->at(row + 1)[column] == color)
      getGroup(board, column, row + 1, group);

  if (column != 0)
    if (board->at(row)[column - 1] == color)
      getGroup(board, column - 1, row, group);

  if (column != board->at(0).size() - 1)
    if (board->at(row)[column + 1] == color)
      getGroup(board, column + 1, row, group);
}

void removeGroup(vector<vector<int>> *board, vector<GameField> group)
{
  for (int i = 0; i < group.size(); i++)
  {
    board->at(group[i].row)[group[i].column] = 0;
  }
}

void closeColumnCaps(vector<vector<int>> *board)
{
  bool anyGaps;
  do
  {
    anyGaps = false;
    for (int i = 0; i < board->at(0).size() - 1; i++)
    {
      bool gap = true;
      for (int j = 0; j < board->size(); j++)
      {
        if (board->at(j)[i] != 0)
          gap = false;
      }

      if (gap)
      {
        anyGaps = true;
        for (int j = 0; j < board->size(); j++)
        {
          board->at(j)[i] = board->at(j)[i + 1];
          board->at(j)[i + 1] = 0;
        }
      }
    }
  } while (anyGaps);
}

void closeGaps(vector<vector<int>> *board)
{
  for (int i = 0; i < board->at(0).size(); i++)
  {
    bool done;
    do
    {
      done = true;
      for (int j = 1; j < board->size(); j++)
      {
        if (board->at(j)[i] == 0 && board->at(j - 1)[i] != 0)
        {
          done = false;
          board->at(j)[i] = board->at(j - 1)[i];
          board->at(j - 1)[i] = 0;
        }
      }
    } while (!done);
  }
}

int makeMove(vector<vector<int>> *board, const int column, const int row)
{
  vector<GameField> group = vector<GameField>(0);

  getGroup(board, column, row, &group);
  removeGroup(board, group);
  closeGaps(board);
  closeColumnCaps(board);

  return group.size() * (group.size() - 1);
}

void init(vector<vector<int>> *board)
{
  srand(time(NULL));
  for (int i = 0; i < board->size(); i++)
  {
    vector<int> row = board->at(i);
    for (int j = 0; j < row.size(); j++)
    {
      //31 - 35 sind die Codes für die Farben, daher + 31
      int color = rand() % 5 + 31;
      row[j] = color;
    }
    board->at(i) = row;
  }
}

void loop(vector<vector<int>> *board)
{
  int row, column, score = 0;

  while (true)
  {
    getInput(&column, &row);

    if (!isValidMove(*board, column, row))
    {
      cout << "Kein gültiger Zug." << endl;
      continue;
    }

    score += makeMove(board, column, row);

    printBoard(*board, score);

    if (isEmpty(*board))
    {
      cout << "Sie haben das Spiel gewonnen!" << endl;
      break;
    }

    if (!moreMovesPossible(*board))
    {
      cout << "Kein weiterer Zug möglich." << endl;
      break;
    }
  }
}

int main()
{
  vector<vector<int>> board(rows, vector<int>(columns));
  init(&board);
  printBoard(board, 0);
  loop(&board);
  return 0;
}