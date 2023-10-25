#ifndef HORSE2_HPP

# define HORSE2_HPP

# include <iostream>
# include <string>
# include "../APieces2.hpp"
# include "../../Board/Board.hpp"

class	Horse2 : public APieces2
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		Horse2(void);
        Horse2(int x, int y, Board &board, int id);
        Horse2(const Horse2 &horse);

        ~Horse2(void);

        Horse2 &operator= (const Horse2 &rook);

        int			*getPos(void);
        std::string getType(void);
        int         getId(void);
        
        int   		move(int x, int y, Board &board, int silence);
        bool     canAttack(int x, int y, Board &board);
        void        setPos(int x, int y);


};

#endif