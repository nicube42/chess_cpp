#ifndef PAWN2_HPP

# define PAWN2_HPP

# include <iostream>
# include <string>
# include "APieces2.hpp"
# include "../Board/Board.hpp"

class	Pawn2 : public APieces2
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		Pawn2(void);
        Pawn2(int x, int y, Board &board, int id);
        Pawn2(const Pawn2 &pawn);

        ~Pawn2(void);

        Pawn2 &operator= (const Pawn2 &cure);

        int			*getPos(void);
        std::string getType(void);
        int         getId(void);
        int   		move(int x, int y, Board &board, int silence);
        bool     canAttack(int x, int y, Board &board);
        void        setPos(int x, int y);


};

#endif