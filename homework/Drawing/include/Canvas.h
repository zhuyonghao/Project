
#ifndef DRAWING_CANVAS_H
#define DRAWING_CANVAS_H

#include <vector>
#include <string>
#include "Shape.h"
#include "LineStyle.h"
#include "FillPattern.h"

class DrawingCanvas
{
public:
    DrawingCanvas();
    ~DrawingCanvas();

    // 可对图形进行删除、拷贝、剪切、平移、恢复和撤销操作；
    void removeShape(Shape *shape);
    void copyShape();
    void cutShape();
    void translateShape();
    void redo();
    void undo();
    // 可完成图形文件的保存、打开、打印且能提供将所绘图形转换为位图进行存储的功能
    void save();
    void open();
    void print();
    void convertToBitmap();
    // 可填充形体、绘制文本；可改变线条颜色、类型、填充方式
    void addShape(Shape *shape);
    void drawShapes();
    void fillShapes();
    void clearShapes();
    void setColor(const Color &color);
    void setFill(bool fill);
    void setLineStyle(const LineStyle &lineStyle);
    void setFillPattern(const FillPattern &fillPattern);

private:
    std::vector<Shape *> shapes;
    static int currentCanvasCount;
};

int DrawingCanvas::currentCanvasCount = 0;

#endif
