#include "connect_four.h"
#include <string>

std::map<ConnecFour::error_code, std::string > ConnecFour::err2str{
	{E_NO_ERROR, "No error occurred"},
	{E_INVALID_LENGTH, "Error occurred: invalid length passed"},
	{E_INVALID_PLAYER, "Error occurred: invalid player selected"},
	{E_EXCEEDED_BOARD_RANGE, "Error occurred: exceeded board range"},
	{E_GAME_STOPPED, "Error occurred: game stopped"}
};
std::map<ConnecFour::winning_direction, std::pair< int, int> > ConnecFour::dir2values{
	{NL_WEST, {0,1}},
	{NL_EAST, {0,-1}},
	{NL_SOUTH,{-1,0}},
	{NL_NORTHWEST,{1,1}},
	{NL_NORTHEAST,{1,-1}},
	{NL_SOUTHWEST,{-1,1}},
	{NL_SOUTHEAST,{-1,-1}}
};
std::map<std::string,ConnecFour::player> ConnecFour::str2player{
	{"Red", 	PLR_RED },
	{"Yellow",	PLR_YELLOW }
};

ConnecFour::Grid::Grid(unsigned short argHight, unsigned short argWidth, unsigned short argWinCL)
	: hight(argHight),
	  width(argWidth),
	  winCondLength(argWinCL),
	  highestIndexNotOccopied_inBorad(width, 0){
	if( hight < winCondLength || width < winCondLength )
		throw E_INVALID_LENGTH;
	if( hight > 26 || width > 26 )
		throw E_INVALID_LENGTH;
	for( unsigned i=0; i<hight; i++)
		board.push_back( std::vector<char>(width, 'w'));
}

void ConnecFour::Grid::makeMove( player plr, char position_played){
	if( plr != PLR_YELLOW && plr != PLR_RED)
		throw E_INVALID_PLAYER;

	unsigned idx = position_played - 65; //ASCII A=65
	if( highestIndexNotOccopied_inBorad[idx] >= hight )
		throw E_EXCEEDED_BOARD_RANGE;
	if( plr == PLR_YELLOW)
		board[highestIndexNotOccopied_inBorad[idx]][idx] = 'y';
	else
		board[highestIndexNotOccopied_inBorad[idx]][idx] = 'r';
	highestIndexNotOccopied_inBorad[idx] ++;
}

unsigned ConnecFour::Grid::countPointsInRay(char position_played, winning_direction dir2check ){
	unsigned currentCnt = 0;
	int coord_x = position_played - 65;
	int coord_y = highestIndexNotOccopied_inBorad[coord_x]-1;
	const char curretnColor = board[coord_y][coord_x];

	while(true){

		coord_x += dir2values[dir2check].second;
		coord_y += dir2values[dir2check].first;
		if( coord_x < 0 || coord_y < 0 || coord_x >= width || coord_y >= hight)
			break;
		else if ( board[coord_y][coord_x] != curretnColor)
			break;
		currentCnt ++;
	}
	return currentCnt;
}
int ConnecFour::Grid::checkGameStatus( char position_played) {
	int coord_x = position_played - 65;
	if( coord_x > 26 || coord_x < 0 )
		return E_EXCEEDED_BOARD_RANGE;

	unsigned counter = 1;
	counter += countPointsInRay(position_played, NL_NORTHWEST);
	counter += countPointsInRay(position_played, NL_SOUTHEAST);
	if( counter >= winCondLength)
		return GAME_STOPS;
	counter = 1;
	counter += countPointsInRay(position_played, NL_WEST);
	counter += countPointsInRay(position_played, NL_EAST);
	if( counter >= winCondLength)
		return GAME_STOPS;
	counter = 1;
	counter += countPointsInRay(position_played, NL_NORTHEAST);
	counter += countPointsInRay(position_played, NL_SOUTHWEST);
	if( counter >= winCondLength)
		return GAME_STOPS;
	counter = 1;
	counter += countPointsInRay(position_played, NL_SOUTH);
	
	if( counter >= winCondLength)
		return GAME_STOPS;
	return GAME_CONTINUES;
}

std::string ConnecFour::who_is_winner(std::vector<std::string> pieces_position_list){
	try{
		Grid Board(6,7,4);
		for( unsigned i=0; i<pieces_position_list.size(); i++){
			char nextMove = pieces_position_list[i][0];
			std::string nextPlayer = pieces_position_list[i].substr(2);
			
			Board.makeMove( str2player[nextPlayer], nextMove);
			int current_game_status = Board.checkGameStatus( nextMove );
			
 			if( current_game_status == GAME_STOPS  )
				return nextPlayer;
		}
		return "Draw";
	}
	catch( ConnecFour::error_code e){
		if( e == E_EXCEEDED_BOARD_RANGE )
			return "Draw";
        return ConnecFour::err2str[e];
	}
}
