#include "rotator.h"

Rotator* Rotator::instance = 0;

void Rotator::rotate(Ppm* input, Ppm* output, int degrees) {
    int magicNum = input->getMagicNum();
    int maxVal = input->getMaxVal();
    int inWidth = input->getWidth();
    int inHeight = input->getHeight();
    std::vector<ColorPixel> inPixels = input->getPixels();

    std::vector<ColorPixel> outPixels(inPixels.size());
    switch (degrees) {
        case 90:
            for (int y = 0; y < inHeight; y++) {
                for (int x = 0; x < inWidth; x++) {
                    outPixels[(x * inHeight) + (inHeight - y - 1)] =
                        inPixels[(y * inWidth) + x];
                }
            }

            output->setMagicNum(magicNum);
            output->setMaxVal(maxVal);
            output->setWidth(inHeight);
            output->setHeight(inWidth);
            output->setPixels(outPixels);
            break;

        case 180:
            for (int y = 0; y < inHeight; y++) {
                for (int x = 0; x < inWidth; x++) {
                    outPixels[((inHeight - y) * inWidth) - x - 1] =
                        inPixels[(y * inWidth) + x];
                }
            }

            output->setMagicNum(magicNum);
            output->setMaxVal(maxVal);
            output->setWidth(inWidth);
            output->setHeight(inHeight);
            output->setPixels(outPixels);
            break;

        case 270:
            /* Does not work on SoC machine
            for (int y = 0; y < inHeight; y++) {
              for (int x = 0; x < inWidth; x++) {
                outPixels[((inWidth * inHeight) - 3 + y) - (inHeight * x)] =
                    inPixels[(y * inWidth) + x];
              }
            } */

            std::vector<ColorPixel> tmpPixels(inPixels.size());
            // Rotate 180
            for (int y = 0; y < inHeight; y++) {
                for (int x = 0; x < inWidth; x++) {
                    tmpPixels[((inHeight - y) * inWidth) - x - 1] =
                        inPixels[(y * inWidth) + x];
                }
            }

            // Rotate 90
            for (int y = 0; y < inHeight; y++) {
                for (int x = 0; x < inWidth; x++) {
                    outPixels[(x * inHeight) + (inHeight - y - 1)] =
                        tmpPixels[(y * inWidth) + x];
                }
            }

            output->setMagicNum(magicNum);
            output->setMaxVal(maxVal);
            output->setWidth(inHeight);
            output->setHeight(inWidth);
            output->setPixels(outPixels);
            break;
    }
}

void Rotator::rotate(Pgm* input, Pgm* output, int degrees) {
    int magicNum = input->getMagicNum();
    int maxVal = input->getMaxVal();
    int inWidth = input->getWidth();
    int inHeight = input->getHeight();
    std::vector<GrayPixel> inPixels = input->getPixels();

    std::vector<GrayPixel> outPixels(inPixels.size());
    switch (degrees) {
        case 90:
            for (int y = 0; y < inHeight; y++) {
                for (int x = 0; x < inWidth; x++) {
                    outPixels[(x * inHeight) + (inHeight - y - 1)] =
                        inPixels[(y * inWidth) + x];
                }
            }

            output->setMagicNum(magicNum);
            output->setMaxVal(maxVal);
            output->setWidth(inHeight);
            output->setHeight(inWidth);
            output->setPixels(outPixels);
            break;

        case 180:
            for (int y = 0; y < inHeight; y++) {
                for (int x = 0; x < inWidth; x++) {
                    outPixels[((inHeight - y) * inWidth) - x - 1] =
                        inPixels[(y * inWidth) + x];
                }
            }

            output->setMagicNum(magicNum);
            output->setMaxVal(maxVal);
            output->setWidth(inWidth);
            output->setHeight(inHeight);
            output->setPixels(outPixels);
            break;

        case 270:
            /* Does not work on SoC machine
            for (int y = 0; y < inHeight; y++) {
              for (int x = 0; x < inWidth; x++) {
                outPixels[((inWidth * inHeight) - 3 + y) - (inHeight * x)] =
                    inPixels[(y * inWidth) + x];
              }
            } */

            std::vector<GrayPixel> tmpPixels(inPixels.size());
            // Rotate 180
            for (int y = 0; y < inHeight; y++) {
                for (int x = 0; x < inWidth; x++) {
                    tmpPixels[((inHeight - y) * inWidth) - x - 1] =
                        inPixels[(y * inWidth) + x];
                }
            }

            // Rotate 90
            for (int y = 0; y < inHeight; y++) {
                for (int x = 0; x < inWidth; x++) {
                    outPixels[(x * inHeight) + (inHeight - y - 1)] =
                        tmpPixels[(y * inWidth) + x];
                }
            }

            output->setMagicNum(magicNum);
            output->setMaxVal(maxVal);
            output->setWidth(inHeight);
            output->setHeight(inWidth);
            output->setPixels(outPixels);
            break;
    }
}