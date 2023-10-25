#ifndef PAWN_HPP

# define PAWN_HPP

# include <iostream>
# include <string>
# include "APieces.hpp"
# include "../Board/Board.hpp"

class	Pawn : public APieces
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		Pawn(void);
        Pawn(int x, int y, Board &board, int id);
        Pawn(const Pawn &pawn);

        ~Pawn(void);

        Pawn &operator= (const Pawn &cure);

        int			*getPos(void);
        std::string getType(void);
        int         getId(void);
        
        int   		move(int x, int y, Board &board, int silence);
        bool     canAttack(int x, int y, Board &board);
        void        setPos(int x, int y);


};

#endif