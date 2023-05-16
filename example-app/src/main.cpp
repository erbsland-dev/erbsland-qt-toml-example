
#include <erbsland/qt/toml/Parser.hpp>
#include <erbsland/qt/toml/Error.hpp>

#include <QCoreApplication>

#include <iostream>


using namespace elqt::toml;


void displayValue(const ValuePtr &value, const QString &path) {
    std::cout << path.toStdString() << "\n";
    std::cout << "Location: " << value->locationRange().toString(LocationFormat::Long).toStdString() << "\n";
    if (value->isTable()) {
        std::cout << "Table: " << value->size() << " Elements" << "\n\n";
        for (const auto &[key, tableValue] : value->toTable()) {
            displayValue(tableValue, path + '/' + key);
        }
    } else if (value->isArray()) {
        std::cout << "Array: " << value->size() << " Elements" << "\n\n";
        auto array = value->toArray();
        for (std::size_t i = 0; i < array.size(); ++i) {
            displayValue(array.at(i), path + QStringLiteral("/[%1]").arg(i));
        }
    } else {
        std::cout << "Value: " << value->toVariant().toString().toStdString() << "\n\n";
    }
}


int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);
    ValuePtr toml{};
    try {
        auto path = QCoreApplication::applicationDirPath() + "/config.toml";
        Parser parser{};
        std::cout << "Reading configuration from: " << path.toStdString() << "\n";
        toml = parser.parseFileOrThrow(path);
    } catch (const Error &err) {
        std::cerr << err.toString().toStdString() << std::endl;
        return 1;
    }
    displayValue(toml, "[root]");
    return 0;
}
