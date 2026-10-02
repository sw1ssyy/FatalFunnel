# Changelog

All notable changes to this project will be documented in this file.


## [Unreleased]

## [0.1.0] - 2026-09-28

### Added

- Raylib-based state machine with `MenuState` and `GameState`.
- `Character` with idle/aim/shoot/reload animations, mouse-aim rotation, and an aiming line.
- `Character` Implemented simple movement mechanics.
- `Animation2D` for sprite-sheet frame playback.
- `DrawUtils::DrawAnimationFrame` shared draw helper for animated, rotated sprites.
- `InputManager` singleton for aim/shoot/movement input queries.
- `TextureManager` and `FontManager` asset caches.
- `Camera2D` in `GameState` with screen-to-world mouse conversion.
- Vendored raylib (prebuilt) and initial game art/font assets.
