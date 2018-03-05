#ifndef IntCell_H
#define IntCell_H

/**
 * A class for simulating an integer memory cell.
 * From Weiss pg. 13
 */


 class IntCell
 {
    public:
    /**
     * Construct the IntCell.
     * Initial value is 0.
     */
    explicit IntCell( int initialValue = 0 );

    /**
     * Return the stored value.
     */
    int read() const;

    /**
     * Change the stored value to x.
     */
   void write( int x );


    private:
        int storedValue;

 };

#endif
