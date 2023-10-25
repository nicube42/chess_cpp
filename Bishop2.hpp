#ifndef BISHOP2_HPP

# define BISHOP2_HPP

# include <iostream>
# include <string>
# include "APieces2.hpp"
# include "Board.hpp"

class	Bishop2 : public APieces2
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		Bishop2(void);
        Bishop2(int x, int y, Board &board, int id);
        Bishop2(const Bishop2 &bishop);

        ~Bishop2(void);

        Bishop2 &operator= (const Bishop2 &bishop);

        int			*getPos(void);
        std::string getType(void);
        int         getId(void);
        
        int   		move(int x, int y, Board &board);
        bool     canAttack(int x, int y, Board &board);
        void        setPos(int x, int y);

};

#endif