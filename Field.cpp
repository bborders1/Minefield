#include "Field.h"
#include <iostream>
#include <vector>

/**
 * Constructor creates a 10x10 grid with no mines by default
**/
 Field::Field()
 {
 	_map.resize(FIELD_DIMENSION);
 	for(unsigned int i=0; i < _map.size(); i++)
 	{
 		_map[i].resize(FIELD_DIMENSION);
 		for(unsigned int j=0; j < _map[i].size(); j++)
 		{
 			_map[i][j] = EMPTY_HIDDEN;
 		}
 	}
 }

/**
 * Overloaded constructor creates a grid that is dim X dim size and
 * initializes it without any mines
**/
 Field::Field(int dim)
 {
 	if(dim>0)
 	{
	 	_map.resize(dim);
	 	for(unsigned int i=0; i < _map.size(); i++)
	 	{
	 		_map[i].resize(dim);
	 		for(unsigned int j=0; j < _map[i].size(); j++)
	 		{
	 			_map[i][j] = EMPTY_HIDDEN;
	 		}
	 	}
	}
 }

/**
 * Returns whether or not the coordinates provided fit within the 
 * valid locations 
**/
 bool Field::inBounds(int col, int row)
 {
 	if(row < 0 || row > FIELD_DIMENSION || col < 0 || col > FIELD_DIMENSION)
 	{
 		return false;
 	}
 	else
 		return true;
 }

 /**
  * Places a mine at the coordinates in the field
 **/
 void Field::placeMine(int col, int row)
 {
 	if( inBounds(col,row) )
 		_map[col][row] = MINE_HIDDEN;
 }

/**
 * Retrieves the state of the field at location col,row
**/
FieldType Field::get(int col, int row)
{
	if( inBounds(col,row) )
 		return _map[col][row];
 	else
 		throw "Out of bounds";
}

/**
 * Returns whether or not _map at (col,row) has a mine and throws an
 * exception if the location is illegal
**/
 bool Field::isSafe(int col, int row)
 {
 	return inBounds(col,row) 
 	       && (_map[col][row] != MINE_HIDDEN && _map[col][row] != MINE_SHOWN);
 }

/**
 * Changes the location from EMPTY_HIDDEN to EMPTY_SHOWN for the 
 * location and any valid locations adjacent (immediately above,
 * below, left, or right as printed) to the provided (col,row) location
**/
void Field::revealAdjacent(int col, int row)
{
	if( inBounds(col,row) 
		|| _map[col][row] == MINE_HIDDEN || _map[col][row] == MINE_SHOWN )
	{
		return;
	}
	else if( _map[col][row] == EMPTY_HIDDEN )
	{
		_map[col][row] = EMPTY_SHOWN;
		revealAdjacent(col-1,row);
		revealAdjacent(col,row-1);
		revealAdjacent(col+1,row);
		revealAdjacent(col,row+1);
	}
}
