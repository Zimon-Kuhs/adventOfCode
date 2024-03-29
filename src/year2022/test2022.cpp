#include "year2022.hpp"
#include "files.hpp"
#include "log.hpp"

#define UNUSED(x) ((void) x)

using namespace adventOfCode;

static size_t failures = 0;

void doTest(const std::string &date, const std::string &actual, const std::string &expected);
std::string output(const std::string &number);

/**
 *  Prints output for each test.
 *
 *  @param date     The test date.
 *  @param actual   The result from the function.
 *  @param expected The expected output.
 */
void doTest(const std::string &date, const std::string &actual, const std::string &expected) {
    const std::string &comparison = expected.empty() ? output(date) : expected;

    const std::string name = "[" + date + "]";
    if (actual == "" || actual == "TBI") {
        echo(name + " -");
    } else if (actual != comparison) {
        echo(name + " " + actual + " != " + comparison + ".");
        ++failures;
    } else {
       echo(name + " +");
    }
}

/**
 *  Reads output from an output file. In case the expected result is big.
 *
 *  @param number   The date to read output for.
 */
std::string output(const std::string &number) {
    return fileAsString(std::filesystem::path("output/" + number + ".txt"));
}

/*
 *  Tests the problems for year 2022.
 *
 *  @author Zimon Kuhs
 *  @date   2022-12-01
 */
int main(int argc, char **argv) {
    UNUSED(argc);
    UNUSED(argv);

    std::vector<std::string> arguments = {};
    arguments.assign(argv + 1, argv + argc);
    const Year2022 year2022 = Year2022(arguments);

    echo("Starting tests.");
    doTest("01", year2022.december01(), "203420");
    doTest("02", year2022.december02(), "12767");
    doTest("03", year2022.december03(), "2616");
    doTest("04", year2022.december04(), "854");
    doTest("05", year2022.december05(), "BRQWDBBJM");
    doTest("06", year2022.december06(), "2260");
    doTest("07", year2022.december07(), "4443914");
    doTest("08", year2022.december08(), "374400");
    doTest("09", year2022.december09(), "2630");
    doTest("10", year2022.december10(), "");
    doTest("11", year2022.december11(), "TBI");
    doTest("12", year2022.december12(), "TBI");
    doTest("13", year2022.december13(), "TBI");
    doTest("14", year2022.december14(), "TBI");
    doTest("15", year2022.december15(), "TBI");
    doTest("16", year2022.december16(), "TBI");
    doTest("17", year2022.december17(), "TBI");
    doTest("18", year2022.december18(), "TBI");
    doTest("19", year2022.december19(), "TBI");
    doTest("20", year2022.december20(), "TBI");
    doTest("21", year2022.december21(), "TBI");
    doTest("22", year2022.december22(), "TBI");
    doTest("23", year2022.december23(), "TBI");
    doTest("24", year2022.december24(), "TBI");
    doTest("25", year2022.december25(), "TBI");
    echo("Tests done.");

    const bool success = failures == 0;
    if (!success) {
        const bool several = failures > 1;
        std::string verb = several ? "were" : "was";
        std::string plural = several ? "s" : "";
        echo("There " + verb + " " + std::to_string(failures) + " failure" + plural + ".");
    }

    return success ? 0 : 1;
}
