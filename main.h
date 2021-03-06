// Main.h: Wenda Zhang
// Include file for the dual network graph visualizer

#ifndef MAIN_H
#define MAIN_H

#define BOOL "b"
#define ARG "a"
#define COMMENT "c"
#define BREAK "x"
#define SEP "h"

#include "util.h"

// Check for gcc version < 4.6, in which case nullptr needs to be implemented
#if __GNUC__ == 4 && __GNUC_MINOR__ < 6
    const                        // this is a const object...
    class {
    public:
      template<class T>          // convertible to any type
        operator T*() const      // of null non-member
        { return 0; }            // pointer...
      template<class C, class T> // or any type of null
        operator T C::*() const  // member pointer...
        { return 0; }
    private:
      void operator&() const;    // whose address can't be taken
    } nullptr = {};              // and whose name is nullptr
#endif

static const char* optStrings[][3] =
{
	{BOOL, "C", "Cplex only (no CBFS)"},
	{BOOL, "D", "Disable callbacks entirely (default)"},
	{BOOL, "b", "Use no contours (BFS)"},
	{BOOL, "w", "Use weighted contour rule (default pw = 1, nw = 1)"},
	{SEP, "", "" },
	{BOOL, "W", "Disable warm starts and cut generation"},
	{BOOL, "R", "Use random contour"},
	{BOOL, "A", "JSON output details of iterations"},
	{BOOL, "U", "Contour selection strategy"},
	{SEP, "", "" },
	{ARG, "d", "Use diving heuristic, set maximum diving depth"},
	{ARG, "p", "Take probing step during diving, set probing interval"},
	{ARG, "r", "Set random seed for CPLEX"},
	{ARG, "t", "Time limit"},
	{ARG, "M", "Measure of best: 1 - worst estimate, 2 - worst lower bound, "
		"3 - best estimate, 4 - best lower bound (default)"},
	{SEP, "", "" },
	{ARG, "L", "LB contour number"},
	{ARG, "P", "Weight for the positive assignments"},
	{ARG, "N", "Weight for the null assignments"},
	{ARG, "j", "JSON output file"},
	{ARG, "E", "Set iteration for early termination"},
	{SEP, "", ""},
	{ARG, "S", "Contour selection option: 1 - Subtree, 2 - WBranch"},
	{ARG, "B", "UCB constant value."},
	{ARG, "u", "Contour selection strategy number of contours"},
	{BOOL, "h", "Help"}
};

int main(int argc, char* argv[]);
const char* parseOpts(int argc, char* argv[], opts& options);
void usage(const char* name);

#endif // MAIN_H
