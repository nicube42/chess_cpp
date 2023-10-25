#ifndef QUEEN2_HPP

# define QUEEN2_HPP

# include <iostream>
# include <string>
# include "APieces2.hpp"
# include "Board.hpp"

class	Queen2 : public APieces2
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		Queen2(void);
        Queen2(int x, int y, Board &board, int id);
        Queen2(const Queen2 &queen);

        ~Queen2(void);

        Queen2 &operator= (const Queen2 &queen);

        int			*getPos(void);
        std::string getType(void);
        int         getId(void);
        
        int   		move(int x, int y, Board &board);
        bool     canAttack(int x, int y, Board &board);
        void        setPos(int x, int y);

};

#endif