#ifndef __CHECKER_H__
#define __CHECKER_H__

#include <string>
#include <memory>

#include "piece.h"
#include "pieceboard.h"

namespace cs427_527
{
  class PieceBoard;

  /**
   * A checker.
   */
  class Checker : public Piece
  {
  public:
    /**
     * Creates a checker owned by the given player at the given position.
     *
     * @param p 0 or 1
     * @param r a nonnegative integer
     * @param c a nonnegative integer
     */
    Checker(int p, int r, int c);

    /**
     * Destroys this checker.
     */
    virtual ~Checker();

    /**
     * Determines if it is legal to move this checker to the
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
     * Moves this checker to the given position on the given board,
     * provided the move is legal, considering the movement rules
     * for a checker.
     *
     * @param board a board
     * @param toR a row on that board
     * @param toC a column on that board
     */
    virtual void makeMove(PieceBoard& board, int toR, int toC);

    /**
     * Returns the index of the player this checker belongs to.
     *
     * @return the index of the owner
     */
    virtual int getPlayer() const;

    /**
     * Returns a printable representation of this checker.
     *
     * @return a printable representation of this checker
     */
    virtual std::string toString() const;
    
  protected:
    /**
     * Determines if it is legal to move this checker to the given
     * location on the board, considering only the contents of
     * that location.
     *
     * @param board the board this checker is on
     * @param toR a row on that board
     * @param toC a column on that board
     * @return true if and only if the move is legal, considering only
     * the contents of the destination
     */
    virtual bool isLegalDestination(const PieceBoard& board, int toR, int toC) const;
    bool isStopOnEdge(const PieceBoard& board, int toR, int toC) const;
    bool isClosePiece(const PieceBoard& board, int toR, int toC) const;
    /**
     * Determines if it is legal to move this checker to the given
     * location, considering only the direction of the move.
     *
     * @param toR a row index
     * @param toC a column index
     * @return true if and only if the move is legal, considering only direction
     */
    virtual bool isLegalDirection(const PieceBoard& board, int toR, int toC) const;

    /**
     * Determines if it is legal to move this checker the given
     * distance, considering only the distance.  The distance is
     * defined as the larger of the change in row and the change in
     * column.
     *
     * @param a nonnegative integer
     * @return true if it is generally legal to move this checker that distance
     */
    virtual bool isLegalDistance(int dist) const;

    /**
     * Returns whether this checker can move backwards.
     *
     * @return true if and only if this checker can move backwards
     */
    virtual bool canMoveBackwards() const;

    /**
     * Updates the given board to reflect the result of jumping this
     * checker to the given location.
     *
     * @param board the board this checker is on
     * @param toR the row of a position on that board diagonally two away
     * from this checker's location
     * @param toC the column of a position on that board diagonally two
     * away from this checker's location
     */
    virtual void jump(PieceBoard& board, int toR, int toC) const;

    /**
     * Determines if this checker is promoted if moving to the given
     * location.
     *
     * @param board the board this checker is on
     * @param toR a row on that board
     * @param toC a column on that board
     * @return true if this checker is promoted
     */
    virtual bool checkPromote(const PieceBoard& board, int toR, int toC) const;

    /**
     * Returns the checker this checker is promoted to.  The new checker
     * is located at the same position as this checker.
     *
     * @return the checker this checker is promoted to
     */
    virtual std::shared_ptr<Piece> promote() const;

    virtual bool getLight() const;

    /**
     * The index of the player this checker belongs to.
     */
    int player;

    /**
     * The row of the position of this checker.
     */
    int row;

    /**
     * The column of the position of this checker.
     */
    int col;
  };
}

#endif
