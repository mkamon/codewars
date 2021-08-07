#pragma once
#include <map>
#include <vector>
#include <string>

namespace ConnecFour{
    enum winning_direction{
        NL_NORTHWEST = 1,
        NL_WEST 	 = 2,
        NL_SOUTHWEST = 3,
        NL_SOUTH 	 = 4,
        NL_SOUTHEAST = 5,
        NL_EAST		 = 6,
        NL_NORTHEAST = 7
    };
    extern std::map<winning_direction, std::pair<int, int> > dir2values;

    enum player{
        PLR_BLANCK  = 0,
        PLR_YELLOW = 1,
        PLR_RED	   = 2
    };
    extern std::map<std::string, player> str2player;

    enum error_code{
        E_NO_ERROR = 0,
        E_INVALID_LENGTH = -1,
        E_INVALID_PLAYER = -2,
        E_EXCEEDED_BOARD_RANGE = -3,
        E_GAME_STOPPED  = -4
    };
    extern std::map<error_code, std::string > err2str;

    enum game_status{
        GAME_CONTINUES = 0,
        GAME_PLAYER_1_WINS = 1,
        GAME_PLAYER_2_WINS = 2,
        GAME_DRAWS 		= 3,
        GAME_STOPS		= 4
    };

    class Grid{
    public:
        Grid(unsigned short argHight, unsigned short argWidth, unsigned short argWinCL);
        void makeMove( player plr, char position_played);
        int checkGameStatus( char position_played);
    private:
        const unsigned short hight;
        const unsigned short width;
        const unsigned short winCondLength;
        std::vector< std::vector<char> > board;
        std::vector< unsigned short> highestIndexNotOccopied_inBorad;

        unsigned countPointsInRay(char position_played, winning_direction dir2check );
    };

    std::string who_is_winner(std::vector<std::string> pieces_position_list);

}