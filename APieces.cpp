#include "APieces.hpp"

APieces::APieces(void) : _type("(null)"), _init_x(0), _init_y(0), _pos_x(0), _pos_y(0), _id(0)
{

}

APieces::APieces(std::string const &type) : _type(type), _init_x(0), _init_y(0), _pos_x(0), _pos_y(0) , _id(0)
{

}

APieces::~APieces()
{

}

APieces::APieces(const APieces &apieces) : _type(apieces._type), _init_x(apieces._init_x), _init_y(apieces._init_y), _pos_x(apieces._pos_x), _pos_y(apieces._pos_y) , _id(apieces._id)
{

}

APieces &APieces::operator= (const APieces &apieces)
{
    return (*this);
}