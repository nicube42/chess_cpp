#ifndef ROOK_HPP

# define ROOK_HPP

# include <iostream>
# include <string>
# include "APieces.hpp"
# include "../Board/Board.hpp"

class	Rook : public APieces
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		Rook(void);
        Rook(int x, int y, Board &board, int id);
        Rook(const Rook &rook);

        ~Rook(void);

        Rook &operator= (const Rook &rook);

        int			*getPos(void);
        std::string getType(void);
        int         getId(void);
        
        int   		move(int x, int y, Board &board, int silence);
        bool     canAttack(int x, int y, Board &board);
        void        setPos(int x, int y);

};

#endif