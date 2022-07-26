```mermaid
classDiagram
    class Tile
    class Engine
    class Renderer

    class Board
    class BoardGenerator
    class Zone
    class Scene

    class Movable {
        <<interface>>
    }

    %% On trigger : 
    class HidingTile

    %% Other tiles can pass through this tile, but something happens upon doing so
    class TriggeringTile
    
    %% Other tiles cannot pass through this tile
    class BlockingTile
    
    class Wall
    class MovingWall
    class Mino
    
    Tile <|-- TriggeringTile
    Tile <|-- BlockingTile

    TriggeringTile <|-- HidingTile

    BlockingTile <|-- Mino
    BlockingTile <|-- Wall

    Wall <|-- MovingWall

    MovingWall *-- Movable

    Mino *-- Movable
```