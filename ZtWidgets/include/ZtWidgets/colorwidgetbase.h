/*
 * Copyright (c) 2013-2016 Victor Wåhlström
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 */

#ifndef COLORWIDGETBASE_H
#define COLORWIDGETBASE_H

#include <QtWidgets/QWidget>

/*! Base class for color manipulating widgets */
class CColorWidgetBase : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Return the color represented by this widget
     * @return The color represented by this widget
     */
    QColor color() const;

    /**
     * @brief Update color
     * @param color The new color
     *
     * @note Does not emit a signal
     *
     * Update the color this widget represents.
     */
    virtual void updateColor(const QColor& color);

    /**
     * @brief Set color
     * @param color The new color
     *
     * Set the color this widget represents. Will emit a colorChanged signal if the color changes.
     */
    void setColor(const QColor& color);

signals:
    /**
     * @param color The new color
     *
     * Emitted when the color has changed.
     */
    void colorChanged(const QColor& color);

    /**
     * @param color The new color
     *
     * Emitted while the color is being changed.
     */
    void colorChanging(const QColor& color);

protected:
    /**
     * @brief Constructor, can be called from subclass
     * @param parent Parent widget
     */
    CColorWidgetBase(QWidget* parent = Q_NULLPTR);

    /**
     * @brief Draw a checkerboard pattern
     * @param painter Painter to use
     * @param rect Bounding rect
     * @param size Size of each square
     */
    static void drawCheckerboard(QPainter& painter, const QRect& rect, quint32 size);

    /// Color represented by this widget
    QColor m_Color;
};

#endif // COLORWIDGETBASE_H
