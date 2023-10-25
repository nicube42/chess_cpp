#ifndef ROOK2_HPP

# define ROOK2_HPP

# include <iostream>
# include <string>
# include "APieces2.hpp"
# include "../Board/Board.hpp"

class	Rook2 : public APieces2
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		Rook2(void);
        Rook2(int x, int y, Board &board, int id);
        Rook2(const Rook2 &rook);

        ~Rook2(void);

        Rook2 &operator= (const Rook2 &rook);

        int			*getPos(void);
        std::string getType(void);
        int         getId(void);
        
        int   		move(int x, int y, Board &board, int silence);
        bool     canAttack(int x, int y, Board &board);
        void        setPos(int x, int y);

};

#endif