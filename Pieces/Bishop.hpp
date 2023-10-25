#ifndef BISHOP_HPP

# define BISHOP_HPP

# include <iostream>
# include <string>
# include "APieces.hpp"
# include "../Board/Board.hpp"

class	Bishop : public APieces
{
	private:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		Bishop(void);
        Bishop(int x, int y, Board &board, int id);
        Bishop(const Bishop &bishop);

        ~Bishop(void);

        Bishop &operator= (const Bishop &bishop);

        int			*getPos(void);
        std::string getType(void);
        int         getId(void);
        
        int   		move(int x, int y, Board &board, int silence);
        bool     canAttack(int x, int y, Board &board);
        void        setPos(int x, int y);



};

#endif