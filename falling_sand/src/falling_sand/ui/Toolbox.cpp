//
// Created by Zachary Smith on 2/4/21.
//

#include "Toolbox.hpp"

namespace falling_sand {
int CELL_SIZE = 25;
int CELL_SPACING = 15;

Toolbox::Toolbox() {
    cells_.push_back(createCell(EMPTY));
    cells_.push_back(createCell(WALL));
    cells_.push_back(createCell(STONE));
    cells_.push_back(createCell(SAND));
    cells_.push_back(createCell(WATER));
    cells_.push_back(createCell(OIL));
    cells_.push_back(createCell(WOOD));
    cells_.push_back(createCell(FIRE));
    cells_.push_back(createCell(ACID));
    cells_.push_back(createCell(ICE));
    cells_.push_back(createCell(LAVA));
    selectedCell_ = 4;
    highlightedCell_ = 4;
    location_ = {CELL_SPACING, CELL_SPACING};
}


bool Toolbox::takeInput(InputSystem &input) {
    Point mousePos = input.mousePos();
    if (mousePos.x >= location_.x &&
        mousePos.x < location_.x + CELL_SIZE &&
        mousePos.y >= location_.y &&
        mousePos.y < location_.y + ((CELL_SIZE + CELL_SPACING) * cells_.size())) {
        int offset = mousePos.y - location_.y;
        int cellIndex = offset / (CELL_SIZE + CELL_SPACING);

        if (!input.mouseDown() &&
            offset % (CELL_SIZE + CELL_SPACING) < CELL_SIZE) {
            highlightedCell_ = cellIndex;
        } else {
            if (input.mouseDown() && highlightedCell_ != -1) {
                selectedCell_ = highlightedCell_;
                return true;
            } else {
                highlightedCell_ = -1;
            }
        }

        return highlightedCell_ != -1;
    }
    return false;
}

Brush &Toolbox::currentBrush() {
    currentBrush_.particle = cells_[selectedCell_];
    currentBrush_.size = 20;
    currentBrush_.type = selectedCell_ == 0 ? Fill : FillEmpty;
    return currentBrush_;
}

void Toolbox::render(SDL_Renderer *renderer) {
    for (int i = 0; i < cells_.size(); i++) {
        renderCell(renderer, location_.x,
                   location_.y + (CELL_SIZE + CELL_SPACING) * i,
                   cells_[i], selectedCell_ == i || highlightedCell_ == i ? 5 : 1);
    }
}

void Toolbox::renderCell(SDL_Renderer *renderer, int x, int y, Cell &cell, int border) {
    int color = getCellColor(cell, 0);
    short red = (color & 0x00FF0000) >> 16;
    short green = (color & 0x0000FF00) >> 8;
    short blue = (color & 0x000000FF);

    rect_.x = x;
    rect_.y = y;
    rect_.w = CELL_SIZE;
    rect_.h = CELL_SIZE;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect_);

    rect_.x = x + border;
    rect_.y = y + border;
    rect_.w = CELL_SIZE - (border * 2);
    rect_.h = CELL_SIZE - (border * 2);
    SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
    SDL_RenderFillRect(renderer, &rect_);
}

}
