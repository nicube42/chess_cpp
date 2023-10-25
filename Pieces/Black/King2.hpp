#ifndef KING2_HPP

# define KING2_HPP

# include <iostream>
# include <string>
# include "../APieces2.hpp"
# include "../../Board/Board.hpp"

class	King2 : public APieces2
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		King2(void);
        King2(int x, int y, Board &board, int id);
        King2(const King2 &king);

        ~King2(void);

        King2 &operator= (const King2 &queen);

        int			*getPos(void);
        std::string getType(void);
        int         castle(int x, int y, Board &board);
        int         getId(void);
        
        int   		move(int x, int y, Board &board, int silence);
        bool     canAttack(int x, int y, Board &board);
        void        setPos(int x, int y);

};

#endif