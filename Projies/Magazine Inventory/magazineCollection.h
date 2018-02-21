#ifndef MAGAZINE_H_INCLUDED
#define MAGAZINE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>

/**
 *
 * Creates a Magazine Collection using LinkedLists
 *
*/

class MagazineCollection {
    private:
        struct Magazine {

            int data; // Unique ID

            std::string magazineName; // Modern Drummer, The Week, Wired, etc.
            std::string issueDate; // mm/yyyy

            std::string magazineType; // music, news, science, education, etc. etc.
            int pageNumber;

            //std::string articleName;
            //std::string articleAuthor;


            //Lesson -> Class for the type of lessons that might be contained in an issue
            //Interview -> Class for an interview
            //Other ideas ...

            Magazine *nextMagazine;

            Magazine();

            Magazine(int data); // Construct by unique ID

            Magazine(std::string magazineName, std::string issueDate); // Construct by magName/issDate

            bool operator==( const Magazine &rhs ) const;

            bool operator!=( const Magazine &rhs ) const;
        };

        Magazine *headMagazine;
        Magazine *tailMagazine;

        int magazines;

    public:
        MagazineCollection();

        MagazineCollection(const MagazineCollection& src);

        ~MagazineCollection();

        void prependMagazine( int to_add ); // add by uniqueID

        void appendMagazine( int to_add ); // add by uniqueID

        int size() const;

        void display(std::ostream& outs) const;

        MagazineCollection& operator=(const MagazineCollection& rhs);
};

inline
int MagazineCollection::size() const
{
    return this->magazines;
}


inline
std::ostream& operator<<( std::ostream &outs, const MagazineCollection &prt )
{
    prt.display(outs);

    return outs;
}



#endif
