#ifndef __PIECEBOARD_H__
#define __PIECEBOARD_H__

#include <string>
#include <iostream>
#include <vector>
#include <memory>

namespace cs427_527
{
  class Piece;

  class PieceBoard
  {
  public:
    enum Color { BLACK, RED };

    /**
     * Creates a checkerboard with pieces in their initial locations.
     */
    PieceBoard();

    /**
     * Destoys this board.
     */
    virtual ~PieceBoard();
    
    /**
     * Returns the piece at the given position on this board, or
     * nullptr if there is no such piece.
     *
     * @param row a row on this board
     * @param col a column on this board
     */
    virtual std::shared_ptr<Piece> getPiece(int row, int col);

    /**
     * Returns the piece at the given position on this board, or
     * nullptr if there is no such piece.
     *
     * @param row a row on this board
     * @param col a column on this board
     */
    virtual std::shared_ptr<const Piece> getPiece(int row, int col) const;

    /**
     * Removes the piece, if any, at the given position on this board.
     *
     * @param row a row on this board
     * @param col a column on this board
     */
    virtual void removePiece(int row, int col);

    /**
     * Places the given checker at the given location on this board.
     *
     * @param row a row on this board
     * @param col a column on this board
     * @param p a checker
     */
    virtual void placePiece(int row, int col, std::shared_ptr<Piece> p);

    /**
     * Returns the width of this board.
     *
     * @return the width of this board
     */
    virtual int getWidth() const;

    /**
     * Returns the height of this board.
     *
     * @return the height of this board
     */
    virtual int getHeight() const;

    /**
     * Returns the color of this board at the given position.
     *
     * @param row a row on this board
     * @param col a column on this board
     * @return the color of that position.
     */
    virtual Color getBoardColor(int row, int col) const;

    /**
     * Returns the index of the player whose turn it is on this board.
     *
     * @return the player whose turn it is
     */
    virtual int getCurrentPlayer() const;

    /**
     * Determines if it is legal to move a piece from the given
     * location to the given location on this board.
     *
     * @param fromR a row on this board
     * @param fromC a column on this board
     * @param toR a row on this board
     * @param toC a column on this board
     * @return true if and only if the move is legal
     */
    virtual bool isLegalMove(int fromR, int fromC, int toR, int toC) const;

    /**
     * Updates this move to reflect the effects of the given move.
     *
     * @param fromR the starting row of a legal move on this board
     * @param fromC the starting column of a legal move on this board
     * @param toR the ending row of a legal move on this board
     * @param toC the ending column of a legal move on this board
     */
    virtual void makeMove(int fromR, int fromC, int toR, int toC);

    /**
     * Determines if the game on this board is over.
     *
     * @return true if and only if the game is over
     */
    virtual bool gameOver() const;

    /**
     * Returns a printable representation of this board.
     *
     * @return a printable representation of this board
     */
    virtual std::string toString() const;
    
    /**
     * Determines if the given position is on this board.
     *
     * @return true if and only if the position is on this board
     */
    virtual bool inBounds(int r, int c) const;

  protected:
    /**
     * Contains the pieces on this board.  board[r][c] is the piece
     * at row r, column c.  A given entry is nullptr if there is no
     * piece.
     */
    std::vector<std::vector<std::shared_ptr<Piece>>> board;

    /**
     * The width of this board.
     */
    int width;

    /**
     * The height of this board.
     */
    int height;

    /**
     * The index of the player whose turn it is.
     */
    int turn;

    /**
     * A pointer to the piece that is in the middle of a sequence
     * of jumps.  This piece is the only one it is legal to move.
     * If there is no such piece, this is nullptr and it is legal
     * to move any piece that has a legal move.
     */
    std::shared_ptr<Piece> jumping;
  };

  /**
   * Outputs a printable representation of this board to the given stream.
   *
   * @param os an output stream
   * @param board a board
   * @return the output stream
   */
  std::ostream& operator<<(std::ostream& os, const PieceBoard& board);
}
  
#endif

