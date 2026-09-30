//
// Created by LucasMCgamer on 29/09/2026.
//

#include "circuit_escape/cells.hpp"

#include <type_traits>

// std::visit llama a la lambda con la alternativa activa del variant.
bool isTraversable(const Cell& cell) {
    return std::visit([](const auto& value) {
        return CellTraits<std::decay_t<decltype(value)>>::traversable;
    }, cell);
}

bool isCollectible(const Cell& cell) {
    return std::visit([](const auto& value) {
        return CellTraits<std::decay_t<decltype(value)>>::collectible;
    }, cell);
}
