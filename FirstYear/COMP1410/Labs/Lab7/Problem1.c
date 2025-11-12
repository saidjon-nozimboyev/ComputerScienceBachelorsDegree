#include <stdio.h>

struct Rectangle 
{
    float lenght;
    float width;
};

struct Rectangle createRectangle(float length, float width) {
    struct Rectangle rect;
    rect.lenght = length;
    rect.width = width;
    return rect;
}

void AreaAndPerimeter(struct Rectangle rect) 
{
    printf("Length: %.2f, Width: %.2f, Area: %.2f, Perimeter:%.2f\n", rect.lenght, rect.width, rect.lenght * rect.width, 2 * (rect.lenght + rect.width));
}

void updateDimensions(struct Rectangle *rect) 
{
    rect->lenght += 1.0;
    rect->width += 1.0;
}

struct Rectangle doubleDimensions(struct Rectangle rect) 
{
    struct Rectangle newRect;
    newRect.lenght = rect.lenght * 2;
    newRect.width = rect.width * 2;
    return newRect;
}


int main() {
    printf("\nEnter length and width of the rectangle: ");
    float length, width;
    scanf("%f %f", &length, &width);

    struct Rectangle rec = createRectangle(length, width);
    printf("Initial Rectangle -> ");
    AreaAndPerimeter(rec);

    updateDimensions(&rec);
    printf("After update -> Lenght: %.2f, Width: %.2f\n", rec.lenght, rec.width);

    struct Rectangle doubledRect = doubleDimensions(rec);
    printf("Doubled Rectangle -> ");
    AreaAndPerimeter(doubledRect);
    
    printf("\n\nChecking original rectangle remains unchanged -> ");
    AreaAndPerimeter(rec);

    printf("\n");
    return 0;
}