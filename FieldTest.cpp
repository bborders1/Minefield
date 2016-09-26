/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
	ASSERT_ANY_THROW( minefield.get(12,12) );
}

TEST(FieldTest, checkIsSafe)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ(false, minefield.isSafe(4,5));
	ASSERT_EQ(true, minefield.isSafe(5,5));
}

TEST(FieldTest, fieldType)
{
	Field minefield;

	minefield.placeMine(4,5);
	ASSERT_EQ(MINE_HIDDEN, minefield.get(4,5));
	ASSERT_EQ(EMPTY_HIDDEN, minefield.get(5,5));
}

TEST(FieldTest, reveal)
{
	Field minefield;

	minefield.placeMine(4,5);
	minefield.revealAdjacent(5,5);
	ASSERT_EQ(EMPTY_SHOWN, minefield.get(5,5));
	ASSERT_EQ(EMPTY_SHOWN, minefield.get(5,6));
	ASSERT_EQ(EMPTY_SHOWN, minefield.get(6,6));
	ASSERT_EQ(MINE_HIDDEN, minefield.get(4,5));
}
