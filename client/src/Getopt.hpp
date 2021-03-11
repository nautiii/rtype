/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Getopt
*/

#ifndef GETOPT_HPP_
#define GETOPT_HPP_

#include <string>

/** @brief The Class to get the Options*/
class Getopt {
    public:
        Getopt(int argc, char *argv[]);
        ~Getopt();

        /** @brief Show the help message to user*/
        void help();

        /** @brief Retrieve if the getOpt is valid or not
         * 
         *  @details
         *   Retrieve a boolean if the getOpt is valid or not.
         *  
         *  @note Return true if the options are valid. False otherwise.
        */
        bool getIsValid() { return _isValid; };

        /** @brief Retrieve the ip */
        std::string getIp() { return _ip; };

        /** @brief Retrieve the port */
        std::string getPort() { return _port; };

    private:
        bool _runGetopt(int argc, char *argv[]);

        bool _isValid;
        std::string _ip;
        std::string _port;
};

#endif /* !GETOPT_HPP_ */
