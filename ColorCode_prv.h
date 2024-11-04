#ifndef COLORCODE_PRV_H
#define COLORCODE_PRV_H

enum MajorColor {WHITE, RED, BLACK, YELLOW, VIOLET};
enum MinorColor {BLUE, ORANGE, GREEN, BROWN, SLATE};

typedef struct 
{
    enum MajorColor majorColor;
    enum MinorColor minorColor;
} ColorPair;

extern const char* MajorColorNames[];
extern int numberOfMajorColors;
extern const char* MinorColorNames[];
extern const int MAX_COLORPAIR_NAME_CHARS;
extern int numberOfMinorColors;

extern int GetPairNumberFromColor(const ColorPair* colorPair);
extern ColorPair GetColorFromPairNumber(int pairNumber);
extern void ColorPairToString(const ColorPair* colorPair, char* buffer) ;
extern void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor);
extern void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber);
extern char* generateColorReferenceManual();

#endif // COLORCODE_PRV_H
