#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include "Workstation.h"
#include <iostream>
#include <vector>

namespace sdds {
    class LineManager {
    private:
        std::vector<Workstation*> m_activeLine {};
        size_t m_cntCustomer { 0 };
        Workstation* m_firstStation { nullptr };
    public:
        // Default Constructor
        LineManager() = default;
        // It loads the contents of the file, stores the address of the next workstation in each element of the collection, identifies the first station in the assembly line and stores its address in the m_firstStation attribute
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        // Reorders the workstations present in the instance variable
        void reorderStations();
        // Performs one iteration of operations on all the workstations in the current assembly line
        bool run(std::ostream& os = std::cout);
        // Displays all active stations on the assembly line in their current order
        void display(std::ostream& os = std::cout) const;
    };
}

#endif // SDDS_LINEMANAGER_H
