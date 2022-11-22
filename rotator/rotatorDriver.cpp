#include <getopt.h>

#include <fstream>
#include <iostream>
#include <string>

#include "pgm.h"
#include "ppm.h"
#include "rotator.h"

using namespace std;

bool loadPpm(Ppm* ppm, const string& fileName, string errMsg);
bool loadPgm(Pgm* pgm, const string& fileName, string errMsg);
void parseHeader(ifstream& f, int* magicNum, int* width, int* height,
                 int* maxVal);
void ppmToFile(Ppm* ppm, const string& fileName);
void pgmToFile(Pgm* pgm, const string& fileName);

int main(int argc, char* argv[]) {
    string orgFileName = argv[1];
    string outFileName = argv[2];
    int degrees = 0;

    // Parse options
    int opt;
    while (optind < argc) {
        if ((opt = getopt(argc, argv, "l:r:")) != EOF) {
            switch (opt) {
                case 'r':
                    degrees = atoi(optarg);
                    optind = argc + 1;
                    break;
                case 'l':
                    degrees = 360 - atoi(optarg);
                    optind = argc + 1;
                    break;
            }
        } else {
            optind++;
        }
    }
    if (optind == argc) {
        cout << "Rotate direction not detected. Try again." << endl;
        return 1;
    }

    // Degrees = 90, 180, 270 only
    if (degrees != 90 && degrees != 180 && degrees != 270) {
        cout << "Please specify degree of 90, 180, or 270 only." << endl;
        return 1;
    }

    Rotator* rotator = rotator->getInstance();

    string fileType = orgFileName.substr(orgFileName.length() - 3, 3);
    string errMsg = "";
    if (fileType == "ppm") {
        Ppm* ppm = new Ppm();

        if (!loadPpm(ppm, orgFileName, errMsg)) {
            cout << errMsg << endl;
            return 1;
        }

        Ppm* rotatedPpm = new Ppm();
        rotator->rotate(ppm, rotatedPpm, degrees);
        ppmToFile(rotatedPpm, outFileName);

    } else if (fileType == "pgm") {
        Pgm* pgm = new Pgm();
        if (!loadPgm(pgm, orgFileName, errMsg)) {
            cout << errMsg << endl;
            return 1;
        }

        Pgm* rotatedPgm = new Pgm();
        rotator->rotate(pgm, rotatedPgm, degrees);
        pgmToFile(rotatedPgm, outFileName);

    } else {
        cout << "Invalid file type. Try again." << endl;
        return 1;
    }

    return 0;
}

void parseHeader(ifstream& f, int* magicNum, int* width, int* height,
                 int* maxVal) {
    char buffer[80];
    int phase = 0, j = 0;
    while (phase < 4) {
        f.getline(buffer, 80);
        if (buffer[0] == '#') continue;

        switch (phase) {
            case 0:
                j = sscanf(buffer, "P%d %d %d %d\n", magicNum, width, height,
                           maxVal);
                break;
            case 1:
                j = sscanf(buffer, "%d %d %d\n", width, height, maxVal);
                break;
            case 2:
                j = sscanf(buffer, "%d %d\n", height, maxVal);
                break;
            case 3:
                j = sscanf(buffer, "%d\n", maxVal);
                break;
            case 4:
                j = 0;
                break;
        }

        phase += j;
    }
}

bool loadPpm(Ppm* ppm, const string& fileName, string errMsg) {
    ifstream f(fileName.c_str(), ios::binary);
    if (f.fail()) {
        errMsg = "Could not open file: " + fileName;
        return false;
    }

    int magicNum, width, height, maxVal;
    parseHeader(f, &magicNum, &width, &height, &maxVal);

    if (magicNum != 3 && magicNum != 6) {
        errMsg = "Unsupported magic number";
        f.close();
        return false;
    }
    if (width < 1) {
        errMsg = "Unsupported width: " + to_string(width);
        f.close();
        return false;
    }
    if (height < 1) {
        errMsg = "Unsupported height: " + to_string(height);
        f.close();
        return false;
    }
    if (maxVal < 1 || maxVal > 255) {
        errMsg = "Unsupported number of bits: " + to_string(maxVal);
        f.close();
        return false;
    }

    vector<ColorPixel> pixels = ppm->getPixels();
    pixels.resize(width * height);

    if (magicNum == 6) {
        for (int i = 0; i < pixels.size(); i++) {
            char r, g, b;
            f.get(r);
            f.get(g);
            f.get(b);
            pixels[i].setR(r);
            pixels[i].setG(g);
            pixels[i].setB(b);
        }

    } else if (magicNum == 3) {
        for (int i = 0; i < pixels.size(); i++) {
            int r, g, b;
            f >> r;
            f >> g;
            f >> b;
            pixels[i].setR(r);
            pixels[i].setG(g);
            pixels[i].setB(b);
        }
    }

    ppm->setMagicNum(magicNum);
    ppm->setMaxVal(maxVal);
    ppm->setWidth(width);
    ppm->setHeight(height);
    ppm->setPixels(pixels);

    f.close();
    return true;
}

bool loadPgm(Pgm* pgm, const string& fileName, string errMsg) {
    ifstream f(fileName.c_str(), ios::binary);
    if (f.fail()) {
        errMsg = "Could not open file: " + fileName;
        return false;
    }

    int magicNum, width, height, maxVal;
    parseHeader(f, &magicNum, &width, &height, &maxVal);

    if (magicNum != 2 && magicNum != 5) {
        errMsg = "Unsupported magic number";
        f.close();
        return false;
    }
    if (width < 1) {
        errMsg = "Unsupported width: " + to_string(width);
        f.close();
        return false;
    }
    if (height < 1) {
        errMsg = "Unsupported height: " + to_string(height);
        f.close();
        return false;
    }
    if (maxVal < 1 || maxVal > 255) {
        errMsg = "Unsupported number of bits: " + to_string(maxVal);
        f.close();
        return false;
    }

    vector<GrayPixel> pixels = pgm->getPixels();
    pixels.resize(width * height);

    if (magicNum == 5) {
        f.get();
        f.read((char*)&pixels[0], pixels.size());

    } else if (magicNum == 2) {
        for (int i = 0; i < pixels.size(); i++) {
            int br;
            f >> br;
            pixels[i].setBr(br);
        }
    }

    pgm->setMagicNum(magicNum);
    pgm->setMaxVal(maxVal);
    pgm->setWidth(width);
    pgm->setHeight(height);
    pgm->setPixels(pixels);

    f.close();
    return true;
}

void ppmToFile(Ppm* ppm, const string& fileName) {
    ofstream f;
    f.open(fileName);
    f << "P" << ppm->getMagicNum() << endl;
    f << ppm->getWidth() << ' ' << ppm->getHeight() << endl;
    f << ppm->getMaxVal() << endl;

    for (ColorPixel pixel : ppm->getPixels()) {
        if (ppm->getMagicNum() == 6) {
            f << pixel.getR() << pixel.getG() << pixel.getB();
        } else {
            f << static_cast<int>(pixel.getR()) << endl;
            f << static_cast<int>(pixel.getG()) << endl;
            f << static_cast<int>(pixel.getB()) << endl;
        }
    }

    f.close();
}

void pgmToFile(Pgm* pgm, const string& fileName) {
    ofstream f;
    f.open(fileName);
    f << "P" << pgm->getMagicNum() << endl;
    f << pgm->getWidth() << ' ' << pgm->getHeight() << endl;
    f << pgm->getMaxVal() << endl;

    for (GrayPixel pixel : pgm->getPixels()) {
        pgm->getMagicNum() == 5 ? f << (pixel.getBr())
                                : f << static_cast<int>(pixel.getBr()) << endl;
    }

    f.close();
}