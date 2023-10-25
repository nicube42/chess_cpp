#ifndef APIECES2_HPP

# define APIECES2_HPP

# include <iostream>
# include <string>
# include "Board.hpp"

class   Board;

class	APieces2
{
	protected:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		APieces2(void);
        APieces2(std::string const &type);
        APieces2(const APieces2 &apieces2);

        virtual ~APieces2(void) = 0;

        APieces2 &operator= (const APieces2 &apieces2);

        virtual int *getPos(void) = 0;

        virtual int    move(int x, int y, Board &board) = 0;
        virtual        std::string getType(void) = 0;
        virtual int    getId(void) = 0;
        virtual bool     canAttack(int x, int y, Board &board) = 0;
        virtual void        setPos(int x, int y) = 0;
};

#endif
