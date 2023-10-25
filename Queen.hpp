#ifndef QUEEN_HPP

# define QUEEN_HPP

# include <iostream>
# include <string>
# include "APieces.hpp"
# include "Board.hpp"

class	Queen : public APieces
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		Queen(void);
        Queen(int x, int y, Board &board, int id);
        Queen(const Queen &queen);

        ~Queen(void);

        Queen &operator= (const Queen &queen);

        int			*getPos(void);
        std::string getType(void);
        int         getId(void);
        
        int   		move(int x, int y, Board &board);
        bool     canAttack(int x, int y, Board &board);
        void        setPos(int x, int y);

};

#endif