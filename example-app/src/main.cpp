
#include <erbsland/qt/toml/Parser.hpp>
#include <erbsland/qt/toml/Error.hpp>

#include <QCoreApplication>

#include <iostream>


using elqt::toml::Parser;
using elqt::toml::Error;


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    try {
        Parser parser{};
        auto toml = parser.parseFile("config.toml");
        // ...
    } catch (const Error &err) {
        std::cerr << err.toString().toStdString() << std::endl;
        exit(1);
    }
}
