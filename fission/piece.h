#ifndef __PIECE_H__
#define __PIECE_H__

#include <string>
#include <memory>

namespace cs427_527
{
  class PieceBoard;

  /**
   * A piece.
   */
  class Piece
  {
  public:
    /**
     * Creates a piece owned by the given player at the given position.
     *
     * @param p 0 or 1
     * @param r a nonnegative integer
     * @param c a nonnegative integer
     */
    Piece(int p, int r, int c);

    /**
     * Destroys this piece.
     */
    virtual ~Piece();

    /**
     * Determines if it is legal to move this piece to the
     * given position on the given board, considering only the
     * movement rules for a checcker.  So this method does not
     * consider turn, can-jump-must-jump rules, or similar rules.
     *
     * @param board a board
     * @param toR a row on that board
     * @param toC a column on that board
     */
    virtual bool isLegalMove(const PieceBoard& board, int toR, int toC) const;

    /**
     * Moves this piece to the given position on the given board,
     * provided the move is legal, considering the movement rules
     * for a piece.
     *
     * @param board a board
     * @param toR a row on that board
     * @param toC a column on that board
     */
    virtual void makeMove(PieceBoard& board, int toR, int toC);

    /**
     * Returns the index of the player this piece belongs to.
     *
     * @return the index of the owner
     */
    virtual int getPlayer() const;

    /**
     * Returns a printable representation of this piece.
     *
     * @return a printable representation of this piece
     */
    virtual std::string toString() const;
    virtual bool getLight() const;
    
  protected:
    /**
     * Determines if it is legal to move this piece to the given
     * location on the board, considering only the contents of
     * that location.
     *
     * @param board the board this piece is on
     * @param toR a row on that board
     * @param toC a column on that board
     * @return true if and only if the move is legal, considering only
     * the contents of the destination
     */
    virtual bool isLegalDestination(const PieceBoard& board, int toR, int toC) const;

    /**
     * Determines if it is legal to move this piece to the given
     * location, considering only the direction of the move.
     *
     * @param toR a row index
     * @param toC a column index
     * @return true if and only if the move is legal, considering only direction
     */
    virtual bool isLegalDirection(const PieceBoard& board,int toR, int toC) const;

    /**
     * Determines if it is legal to move this piece the given
     * distance, considering only the distance.  The distance is
     * defined as the larger of the change in row and the change in
     * column.
     *
     * @param a nonnegative integer
     * @return true if it is generally legal to move this piece that distance
     */
    virtual bool isLegalDistance(int dist) const;


    /**
     * Determines if it is legal to move this piece to the given location,
     * considering only the contents of the space in between.
     *
     * @param board the board this piece is on
     * @param toR the row of a position on that board diagonally two away
     * from this piece's location
     * @param toC the column of a position on that board diagonally two
     * away from this piece's location
     * @return true if and only if the move is legal, considering only
     * the contents of the space between
     */
    virtual bool isLegalJump(const PieceBoard& board, int toR, int toC) const;

    /**
     * Returns whether this piece can move backwards.
     *
     * @return true if and only if this piece can move backwards
     */
    virtual bool canMoveBackwards() const;

    /**
     * Updates the given board to reflect the result of jumping this
     * piece to the given location.
     *
     * @param board the board this piece is on
     * @param toR the row of a position on that board diagonally two away
     * from this piece's location
     * @param toC the column of a position on that board diagonally two
     * away from this piece's location
     */
    virtual void jump(PieceBoard& board, int toR, int toC) const;

    /**
     * Determines if this piece is promoted if moving to the given
     * location.
     *
     * @param board the board this piece is on
     * @param toR a row on that board
     * @param toC a column on that board
     * @return true if this piece is promoted
     */
    virtual bool checkPromote(const PieceBoard& board, int toR, int toC) const;

    /**
     * Returns the piece this piece is promoted to.  The new piece
     * is located at the same position as this piece.
     *
     * @return the piece this piece is promoted to
     */
    virtual std::shared_ptr<Piece> promote() const;

    /**
     * The index of the player this piece belongs to.
     */
    int player;

    /**
     * The row of the position of this piece.
     */
    int row;

    /**
     * The column of the position of this piece.
     */
    int col;
  };
}

#endif
