#ifndef APIECES_HPP

# define APIECES_HPP

# include <iostream>
# include <string>
# include "../Board/Board.hpp"

class   Board;

class	APieces
{
	protected:
		std::string			_type;
        int                 _id;
		const int			_init_x;
		const int			_init_y;
        int					_pos_x;
        int					_pos_y;
        
	public:
		APieces(void);
        APieces(std::string const &type);
        APieces(const APieces &apieces);

        virtual ~APieces(void) = 0;

        APieces &operator= (const APieces &apieces);

        virtual int         *getPos(void) = 0;
        virtual std::string getType(void) = 0;
        virtual int         getId(void) = 0;

        virtual int    move(int x, int y, Board &board, int silence) = 0;
        virtual bool     canAttack(int x, int y, Board &board) = 0;
        virtual void        setPos(int x, int y) = 0;
};

void addLogMessage(const std::string& message);

#endif
