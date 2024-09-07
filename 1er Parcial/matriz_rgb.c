#include <stdio.h>
#include <assert.h>

#define N 3 // Global constant that defines the number of rows
#define M 5 // Global constant that defines the amount of pixels per row
#define RGB_M (3 * M)

#define R 0.2989
#define G 0.5870
#define B 0.1140

// Receives a matrix that contains N row of M pixels and converts it to an N row of M rgb gray values
void rgbToGray(const unsigned char rgbMatrix[][RGB_M], unsigned char grayMatrix[][M]);

// Solo para testing
static void assertMatrixEquals(const unsigned char(expected[])[M], const unsigned char(actual[])[M], size_t fils, size_t cols);

int main(void)
{
    unsigned char rgbMatrix[][RGB_M] = {
        {100, 200, 100, 100, 180, 100, 200, 100, 120, 110, 123, 122, 100, 120, 122},
        {101, 200, 105, 99, 200, 100, 201, 102, 118, 110, 120, 120, 100, 121, 122},
        {100, 200, 100, 100, 210, 105, 200, 100, 100, 120, 120, 100, 100, 122, 121}};
    unsigned char grayscaleMatrix[N][M];
    rgbToGray(rgbMatrix, grayscaleMatrix);
    unsigned char expectedGrayscaleMatrix[][M] = {
        {158, 146, 132, 118, 114},
        {159, 158, 133, 116, 114},
        {158, 165, 129, 117, 115}};
    assertMatrixEquals(expectedGrayscaleMatrix, grayscaleMatrix, N, M);

    puts("OK!\n");
    return 0;
}

/**
 * Tester
 */
static void
assertMatrixEquals(const unsigned char(expected[])[M], const unsigned char(actual[])[M], size_t fils, size_t cols)
{
    for (int i = 0; i < fils; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            assert(expected[i][j] == actual[i][j]);
        }
    }
}

void rgbToGray(const unsigned char rgbMatrix[][RGB_M], unsigned char grayMatrix[][M])
{
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < RGB_M; i += 3)
        {
            grayMatrix[j][i/3] = rgbMatrix[j][i] * R + rgbMatrix[j][i + 1] * G + rgbMatrix[j][i + 2] * B;
        }
    }
}
