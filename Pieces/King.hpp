#ifndef KING_HPP

# define KING_HPP

# include <iostream>
# include <string>
# include "APieces.hpp"
# include "../Board/Board.hpp"

class	King : public APieces
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		King(void);
        King(int x, int y, Board &board, int id);
        King(const King &king);

        ~King(void);

        King &operator= (const King &queen);

        int			*getPos(void);
        std::string getType(void);
        int         getId(void);
        
        int   		move(int x, int y, Board &board, int silence);
        bool     canAttack(int x, int y, Board &board);
        int         castle(int x, int y, Board &board);
        void        setPos(int x, int y);

};

#endif