#include "log.hpp"
#include "year2022.hpp"

#define UNUSED(x) ((void) x)

using namespace adventOfCode;

static size_t failures = 0;

void doTest(const std::string &date, const std::string &actual, const std::string &expected) {
    if (actual != expected) {
        echo("[" + date + "] " + actual + " != " + expected + ".");
        ++failures;
    }
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

    const Year2022 year2022 = Year2022();

    echo("Starting tests.");
    doTest("01", year2022.december01(), "203420");
    doTest("02", year2022.december02(), "12767");
    doTest("03", year2022.december03(), "2616");
    doTest("04", year2022.december04(), "854");
    doTest("05", year2022.december05(), "BRQWDBBJM");
    doTest("06", year2022.december06(), "TBI");
    doTest("07", year2022.december07(), "TBI");
    doTest("08", year2022.december08(), "TBI");
    doTest("09", year2022.december09(), "TBI");
    doTest("10", year2022.december10(), "TBI");
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
