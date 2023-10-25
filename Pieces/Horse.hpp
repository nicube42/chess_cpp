#ifndef HORSE_HPP

# define HORSE_HPP

# include <iostream>
# include <string>
# include "APieces.hpp"
# include "../Board/Board.hpp"

class	Horse : public APieces
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		Horse(void);
        Horse(int x, int y, Board &board, int id);
        Horse(const Horse &horse);

        ~Horse(void);

        Horse &operator= (const Horse &rook);

        int			*getPos(void);
        std::string getType(void);
        int         getId(void);
        
        int   		move(int x, int y, Board &board, int silence);
        bool     canAttack(int x, int y, Board &board);
        void        setPos(int x, int y);


};

#endif