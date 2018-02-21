#include "magazineCollection.h"

MagazineCollection::Magazine::Magazine()
{
    this->data = 0; // Unique ID
    this->magazineName = ""; // Modern Drummer, The Week, Wired, etc.
    this->issueDate = ""; // mm/yyyy
    this->magazineType = ""; // music, news, science, education, etc. etc.
    this->pageNumber = 0; //Page number 0 = Cover
    this->nextMagazine = nullptr;
}

// Construct by UniqueID
MagazineCollection::Magazine::Magazine(int data)
{
    this->data = data;
    this->magazineName = "";
    this->issueDate = issueDate;
    this->magazineType = "";
    this->pageNumber = 0;
    this->nextMagazine = nullptr;
}

// Construct by magazineName and issueDate
MagazineCollection::Magazine::Magazine(std::string magazineName, std::string issueDate)
{
    this->data = 0;
    this->magazineName = magazineName;
    this->issueDate = issueDate;
    this->magazineType = "";
    this->pageNumber = 0;
    this->nextMagazine = nullptr;
}

bool MagazineCollection::Magazine::operator==( const Magazine &rhs ) const
{
    return (
        this->data == rhs.data &&
        this->magazineName == rhs.magazineName &&
        this->issueDate == rhs.issueDate &&
        this->magazineType == rhs.magazineType &&
        this->pageNumber == rhs.pageNumber &&
        this->nextMagazine == rhs.nextMagazine
    );
}

bool MagazineCollection::Magazine::operator!=( const Magazine &rhs ) const
{
    return (
        this->data != rhs.data ||
        this->magazineName != rhs.magazineName ||
        this->issueDate != rhs.issueDate ||
        this->magazineType != rhs.magazineType ||
        this->pageNumber != rhs.pageNumber ||
        this->nextMagazine != rhs.nextMagazine
    );
}

MagazineCollection::MagazineCollection()
{
    //Initialize the private data members (attributes)
    headMagazine  = nullptr;
    tailMagazine  = nullptr;
    magazines = 0;
}

MagazineCollection::MagazineCollection(const MagazineCollection& src)
{
    // Important - every constructor must initialize
    // every private data member (attribute)
    this->headMagazine  = nullptr;
    this->tailMagazine  = nullptr;
    this->magazines = 0;

    // Start the Copy Operations
    Magazine* srcIt = src.headMagazine;

    while (srcIt != nullptr) {
        this->appendMagazine(srcIt->data);

        srcIt = srcIt->nextMagazine;
    }
}

MagazineCollection::~MagazineCollection()
{
    Magazine *this_iterator = nullptr; // Loop control pointer
    Magazine *to_delete     = nullptr; // Magazine to delete

    //start at the beginning of the this
    this_iterator = this->headMagazine;

    //iterate through the this and delete each magazine
    while( this_iterator != nullptr  ){
        to_delete = this_iterator;

        //move to next magazine
        this_iterator = this_iterator->nextMagazine;

        //delete the current magazine
        delete to_delete;

        to_delete = nullptr; //dangling pointers are bad

        // Debugging Output
        std::cerr << "Deleting Magazine" << "\n";
    }

    // Debugging Output
    std::cerr << "Deleted Magazine Collection" << "\n";

    // Cleansy Upsies
    headMagazine  = nullptr;
    tailMagazine  = nullptr;
    magazines = 0;
}

void MagazineCollection::prependMagazine( int to_add )
{
    // Create a new Magazine
    Magazine *new_magazine = nullptr;

    // If this is the first magazine
    // invoke appendMagazine

    if( this->magazines == 0 ){
        appendMagazine( to_add );
        return;
    }

    new_magazine = new Magazine( to_add );

    // Setup the new Magazine
    new_magazine->nextMagazine = ( this->headMagazine );
    this->headMagazine = new_magazine;

    // Increase the number of magazines
    this->magazines++;

    // Do not allow access to the Magazine except
    // through the linked list
    new_magazine = nullptr;
}

void MagazineCollection::appendMagazine( int to_add )
{
    // Create a new Magazine
    Magazine *new_magazine = nullptr;

    // Store the "to_add" data within the Magazine
    new_magazine = new Magazine( to_add );

    // Handle the case where the first Magazine is added
    if( this->magazines == 0){
        // this->head = this->tail = new_node;
        this->headMagazine = new_magazine;
        this->tailMagazine = new_magazine;
    }
    else{
        // Add the new node to the this
        (this->tailMagazine)->nextMagazine = new_magazine;
        this->tailMagazine = new_magazine;
    }

    // Increase the number of magazines
    this->magazines++;

    // Do not allow access to the Magazine except
    // through the linked list
    new_magazine = nullptr;
}


void MagazineCollection::display(std::ostream& outs) const
{
    int index = 0;   // Used to output UniqueIDs
    Magazine* it  = this->headMagazine;

    while(it != nullptr)
    {
        outs << "Magazine ID# " << std::right << std::setw(4) << index
             << " - "     << std::right << std::setw(4) << it->data
             << "\n";

        // increment index
        index++;

        it = it->nextMagazine;
    }
}

MagazineCollection& MagazineCollection::operator=(const MagazineCollection& rhs)
{
    // MagazineCollection lhs = rhs;
    // MagazineCollection x;
    // x = x; // self-assignment

    if (this != &rhs)  // NECESSARY self-assignment check
    {
        // Destructor for this
        Magazine *this_iterator = nullptr; // Loop control pointer
        Magazine *to_delete     = nullptr; // Magazine to delete

        //start at the beginning of the this
        this_iterator = this->headMagazine;

        //iterate through the this and delete each node
        while( this_iterator != nullptr  ){
            to_delete = this_iterator;

            //move to next node
            this_iterator = this_iterator->nextMagazine;

            //delete the current node
            delete to_delete;

            to_delete = nullptr; //dangling pointers are bad

            // Debugging output
            std::cerr << "Deleting Magazine" << "\n";
        }

        headMagazine  = nullptr;
        tailMagazine  = nullptr;
        magazines = 0;

        // Copy rhs into this
        Magazine* srcIt = rhs.headMagazine;

        while (srcIt != nullptr) {
            this->appendMagazine(srcIt->data);

            srcIt = srcIt->nextMagazine;
        }
    }

    return *this;
}
