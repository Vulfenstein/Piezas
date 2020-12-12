/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, reset_check)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.reset();
	Piece result = board.pieceAt(BOARD_ROWS-1, 0);
	ASSERT_EQ(result, Blank);
}

TEST(PiezasTest, dropPiece_once)
{
	Piezas board;
	Piece result = board.dropPiece(0);
	ASSERT_EQ(result, X);
}

TEST(PiezasTest, dropPiece_twice)
{
	Piezas board;
	board.dropPiece(0);
	Piece result = board.dropPiece(1);
	ASSERT_EQ(result, O);
}

TEST(PiezasTest, dropPiece_column_full)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	Piece result = board.dropPiece(0);
	ASSERT_EQ(result, Blank);
}

TEST(PiezasTest, dropPiece_column_over)
{
	Piezas board;
	Piece result = board.dropPiece(10);
	ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, dropPiece_column_under)
{
	Piezas board;
	Piece result = board.dropPiece(-10);
	ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, pieceAt_blank)
{
	Piezas board;
	Piece result = board.pieceAt(1,1);
	ASSERT_EQ(result, Blank);
}

TEST(PiezasTest, pieceAt_X)
{
	Piezas board;
	board.dropPiece(0);
	Piece result = board.pieceAt(0, 0);
	ASSERT_EQ(result, X);
}

TEST(PiezasTest, pieceAt_H_over)
{
	Piezas board;
	Piece result = board.pieceAt(10,2);
	ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, pieceAt_H_under)
{
	Piezas board;
	Piece result = board.pieceAt(-10,2);
	ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, pieceAt_V_over)
{
	Piezas board;
	Piece result = board.pieceAt(2,10);
	ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, pieceAt_V_under)
{
	Piezas board;
	Piece result = board.pieceAt(2,-10);
	ASSERT_EQ(result, Invalid);
}

TEST(PiezasTest, gameState_X_H_win)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(1);
  board.dropPiece(0);
  board.dropPiece(2);
  board.dropPiece(1);
  board.dropPiece(3);
  board.dropPiece(1);
  board.dropPiece(3);
  board.dropPiece(2);
  board.dropPiece(3);
  board.dropPiece(2);

	
	Piece result = board.gameState();
	ASSERT_EQ(result, X);
}

TEST(PiezasTest, gameState_X_V_win)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(3);
	board.dropPiece(0);
	board.dropPiece(1);  
	
	Piece result = board.gameState();
	ASSERT_EQ(result, X);
}

TEST(PiezasTest, gameState_O_H_win)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(3);

	
	Piece result = board.gameState();
	ASSERT_EQ(result, O);
}

TEST(PiezasTest, gameState_O_V_win)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(3);
	board.dropPiece(0);
	board.dropPiece(1);  
	
	Piece result = board.gameState();
	ASSERT_EQ(result, O);
}
