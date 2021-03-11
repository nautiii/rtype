/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <string>

/** @brief Contains every objects that make the mediator work */
namespace mediator {

/** @brief The interface for the events
 * 
 *  @details
 *   Every events must be inherited of this class to work correctly
*/
class IEvent {
    public:
        virtual ~IEvent() = default;

        virtual const std::string &get_type() const = 0;

    protected:
    private:
};

}
#endif /* !EVENT_HPP_ */
