#include </opt/homebrew/Cellar/sfml/2.6.0/include/SFML/Graphics.hpp>
#include "Board.hpp"
#include "whiteSetup.hpp"
#include "blackSetup.hpp"

sf::Texture squareGrayLightTexture;
sf::Texture squareGrayDarkTexture;
sf::Sprite squareGrayLightSprite;
sf::Sprite squareGrayDarkSprite;
sf::Texture wRookTexture, wQueenTexture, wPawnTexture, wKnightTexture, wKingTexture, wBishopTexture;
sf::Sprite wRookSprite, wQueenSprite, wPawnSprite, wKnightSprite, wKingSprite, wBishopSprite;
sf::Texture bRookTexture, bQueenTexture, bPawnTexture, bKnightTexture, bKingTexture, bBishopTexture;
sf::Sprite bRookSprite, bQueenSprite, bPawnSprite, bKnightSprite, bKingSprite, bBishopSprite;

// Assumes 8x8 board and each tile is 64x64 pixels
const int TILE_SIZE = 128;

void resetAllSpritesToOriginalScale() {
    float scale_factor = TILE_SIZE / float(wRookSprite.getGlobalBounds().width);
	wRookSprite.setScale(scale_factor, scale_factor);
	float scale_factor_b = TILE_SIZE / float(bRookSprite.getGlobalBounds().width);
	bRookSprite.setScale(scale_factor_b, scale_factor_b);

	float scale_factor_c = TILE_SIZE / float(wQueenSprite.getGlobalBounds().width);
	wQueenSprite.setScale(scale_factor_c, scale_factor_c);
	float scale_factor_d = TILE_SIZE / float(bQueenSprite.getGlobalBounds().width);
	bQueenSprite.setScale(scale_factor_d, scale_factor_d);

	float scale_factor_e = TILE_SIZE / float(wKingSprite.getGlobalBounds().width);
	wKingSprite.setScale(scale_factor_e, scale_factor_e);
	float scale_factor_f = TILE_SIZE / float(bKingSprite.getGlobalBounds().width);
	bKingSprite.setScale(scale_factor_f, scale_factor_f);

	float scale_factor_g = TILE_SIZE / float(wBishopSprite.getGlobalBounds().width);
	wBishopSprite.setScale(scale_factor_g, scale_factor_g);
	float scale_factor_h = TILE_SIZE / float(bBishopSprite.getGlobalBounds().width);
	bBishopSprite.setScale(scale_factor_h, scale_factor_h);

	float scale_factor_i = TILE_SIZE / float(wKnightSprite.getGlobalBounds().width);
	wKnightSprite.setScale(scale_factor_i, scale_factor_i);
	float scale_factor_j = TILE_SIZE / float(bKnightSprite.getGlobalBounds().width);
	bKnightSprite.setScale(scale_factor_j, scale_factor_j);

	float scale_factor_k = TILE_SIZE / float(wPawnSprite.getGlobalBounds().width);
	wPawnSprite.setScale(scale_factor_k, scale_factor_k);
	float scale_factor_l = TILE_SIZE / float(bPawnSprite.getGlobalBounds().width);
	bPawnSprite.setScale(scale_factor_l, scale_factor_l);
}

void	setTextures()
{
	// Load textures
	squareGrayLightTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/square gray light _png_shadow_1024px.png");
	squareGrayDarkTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/square gray dark _png_shadow_1024px.png");

	// Set textures to sprites
	squareGrayLightSprite.setTexture(squareGrayLightTexture);
	squareGrayDarkSprite.setTexture(squareGrayDarkTexture);

	// Load textures for chess pieces
    wRookTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/w_rook_png_shadow_1024px.png");
    wQueenTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/w_queen_png_shadow_1024px.png");
    wPawnTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/w_pawn_png_shadow_1024px.png");
    wKnightTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/w_knight_png_shadow_1024px.png");
    wKingTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/w_king_png_shadow_1024px.png");
    wBishopTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/w_bishop_png_shadow_1024px.png");
	bRookTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/b_rook_png_shadow_1024px.png");
    bQueenTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/b_queen_png_shadow_1024px.png");
    bPawnTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/b_pawn_png_shadow_1024px.png");
    bKnightTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/b_knight_png_shadow_1024px.png");
    bKingTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/b_king_png_shadow_1024px.png");
    bBishopTexture.loadFromFile("/Users/nicolasdiamantis/Documents/Code/cpp/chess_cpp/PNGs/With Shadow/1024px/b_bishop_png_shadow_1024px.png");

    // Set textures to sprites for chess pieces
    wRookSprite.setTexture(wRookTexture);
    wQueenSprite.setTexture(wQueenTexture);
    wPawnSprite.setTexture(wPawnTexture);
    wKnightSprite.setTexture(wKnightTexture);
    wKingSprite.setTexture(wKingTexture);
    wBishopSprite.setTexture(wBishopTexture);
	bRookSprite.setTexture(bRookTexture);
    bQueenSprite.setTexture(bQueenTexture);
    bPawnSprite.setTexture(bPawnTexture);
    bKnightSprite.setTexture(bKnightTexture);
    bKingSprite.setTexture(bKingTexture);
    bBishopSprite.setTexture(bBishopTexture);

	float scale_factor = TILE_SIZE / float(wRookSprite.getGlobalBounds().width);
	wRookSprite.setScale(scale_factor, scale_factor);
	float scale_factor_b = TILE_SIZE / float(bRookSprite.getGlobalBounds().width);
	bRookSprite.setScale(scale_factor_b, scale_factor_b);

	float scale_factor_c = TILE_SIZE / float(wQueenSprite.getGlobalBounds().width);
	wQueenSprite.setScale(scale_factor_c, scale_factor_c);
	float scale_factor_d = TILE_SIZE / float(bQueenSprite.getGlobalBounds().width);
	bQueenSprite.setScale(scale_factor_d, scale_factor_d);

	float scale_factor_e = TILE_SIZE / float(wKingSprite.getGlobalBounds().width);
	wKingSprite.setScale(scale_factor_e, scale_factor_e);
	float scale_factor_f = TILE_SIZE / float(bKingSprite.getGlobalBounds().width);
	bKingSprite.setScale(scale_factor_f, scale_factor_f);

	float scale_factor_g = TILE_SIZE / float(wBishopSprite.getGlobalBounds().width);
	wBishopSprite.setScale(scale_factor_g, scale_factor_g);
	float scale_factor_h = TILE_SIZE / float(bBishopSprite.getGlobalBounds().width);
	bBishopSprite.setScale(scale_factor_h, scale_factor_h);

	float scale_factor_i = TILE_SIZE / float(wKnightSprite.getGlobalBounds().width);
	wKnightSprite.setScale(scale_factor_i, scale_factor_i);
	float scale_factor_j = TILE_SIZE / float(bKnightSprite.getGlobalBounds().width);
	bKnightSprite.setScale(scale_factor_j, scale_factor_j);

	float scale_factor_k = TILE_SIZE / float(wPawnSprite.getGlobalBounds().width);
	wPawnSprite.setScale(scale_factor_k, scale_factor_k);
	float scale_factor_l = TILE_SIZE / float(bPawnSprite.getGlobalBounds().width);
	bPawnSprite.setScale(scale_factor_l, scale_factor_l);
}


void drawBoardAndPieces(sf::RenderWindow& window, Board* board) {

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            // Determine the color of the square based on its position
            bool isLightSquare = (x + y) % 2 == 0;

            sf::Sprite* currentSquareSprite;
            if (isLightSquare) {
                currentSquareSprite = &squareGrayLightSprite;  // Or use squareBrownLightSprite based on your preference
            } else {
                currentSquareSprite = &squareGrayDarkSprite;  // Or use squareBrownDarkSprite based on your preference
            }
            
            currentSquareSprite->setPosition(x * TILE_SIZE, y * TILE_SIZE);
            window.draw(*currentSquareSprite);
        }
    }

	// Draw the chess pieces based on board state
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            APieces* whitePiece = board->getTypeW(x, y);
            APieces2* blackPiece = board->getTypeB(x, y);

			int flippedY = 7 - y;

            if (whitePiece != 0) {
                // Draw white piece based on type
                std::string pieceType = whitePiece->getType(); // Assuming you have a getType method
                if (pieceType == "rook") {
                    wRookSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(wRookSprite);
                }
				if (pieceType == "bishop") {
                    wBishopSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(wBishopSprite);
                }
				if (pieceType == "horse") {
                    wKnightSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(wKnightSprite);
                }
				if (pieceType == "pawn") {
                    wPawnSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(wPawnSprite);
                }
				if (pieceType == "queen") {
                    wQueenSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(wQueenSprite);
                }
				if (pieceType == "king") {
                    wKingSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(wKingSprite);
                }
            }	else if (blackPiece != 0) {
                // Draw black piece based on type
                std::string pieceType = blackPiece->getType(); // Assuming you have a getType method
                if (pieceType == "rook") {
                    bRookSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(bRookSprite);
                }
				if (pieceType == "bishop") {
                    bBishopSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(bBishopSprite);
                }
				if (pieceType == "horse") {
                    bKnightSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(bKnightSprite);
                }
				if (pieceType == "pawn") {
                    bPawnSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(bPawnSprite);
                }
				if (pieceType == "queen") {
                    bQueenSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(bQueenSprite);
                }
				if (pieceType == "king") {
                    bKingSprite.setPosition(x * TILE_SIZE, flippedY * TILE_SIZE);
                    window.draw(bKingSprite);
                }
            }
        }
    }
}

sf::Vector2i getBoardPositionFromMousePosition(int mouseX, int mouseY) {
    return sf::Vector2i(mouseX / TILE_SIZE, mouseY / TILE_SIZE);
}

enum class Player { WHITE, BLACK };

int main() {
    const int TILE_SIZE = 128; // Assuming TILE_SIZE is 64, change this if it's different
    sf::RenderWindow window(sf::VideoMode(8 * TILE_SIZE, 8 * TILE_SIZE), "SFML Chess");

    Board board;
    WhiteBoardSetup white(&board);
    BlackBoardSetup black(&board);
	int				turn = 0;

	setTextures();

	APieces* selectedWhitePiece = nullptr;
	APieces2* selectedBlackPiece = nullptr;
	Player currentPlayer = Player::WHITE;
	
    while (window.isOpen()) {
        sf::Event event;
    	while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i boardPos;
					boardPos = getBoardPositionFromMousePosition(event.mouseButton.x, event.mouseButton.y);
					boardPos.y = 7 - boardPos.y;
					if (currentPlayer == Player::WHITE)
					{
						if (selectedWhitePiece == nullptr)
						{
							if (board.isTaken(boardPos.x, boardPos.y))
								selectedWhitePiece = board.getTypeW(boardPos.x, boardPos.y);
						}
						else
						{
							if (selectedWhitePiece->move(boardPos.x, boardPos.y, board))
								currentPlayer = Player::BLACK;
							selectedWhitePiece = nullptr;
						}
					}
					else
					{
						if (selectedBlackPiece == nullptr)
						{
							if (board.isTaken(boardPos.x, boardPos.y))
								selectedBlackPiece = board.getTypeB(boardPos.x, boardPos.y);
						}
						else
						{
							if (selectedBlackPiece->move(boardPos.x, boardPos.y, board))
								currentPlayer = Player::WHITE;
							selectedBlackPiece = nullptr;
						}
					}
				}
			}
		}

		window.clear();
        drawBoardAndPieces(window, &board);
        window.display();
	}
    return 0;
}
