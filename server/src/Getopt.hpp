/*
** EPITECH PROJECT, 2020
** B-CPP-501-PAR-5-1-rtype-gaetan.depin
** File description:
** Getopt
*/

#ifndef GETOPT_HPP_
#define GETOPT_HPP_

class Getopt {
    public:
        Getopt(int argc, char *argv[]);
        ~Getopt();

        void help();
        
        int getPort() { return _port; };
        bool getIsValid() { return _isValid; };

    private:
        bool _runGetopt(int argc, char *argv[]);

        int _port;
        bool _isValid;
};

#endif /* !GETOPT_HPP_ */
