- Character Pictures
  - Neutral
  - Cheer
  - Inquisitive
  - Upset
  - Performing Skill
  - Won
  - Lost

## Gameplay
---
Minos are generated and fall from the top of the game board. The player can move them as they fall down, but multiple can be falling at once. The goal is to create trains of Minos and activate the train to collect points. If the Minos reach the top of the board, the game is over.

Can store currently falling Mino
    - Queue to release next
    - Swap with currently falling Mino

## Scoring
---
Clicking a highlighted train will tally up a score to add to the total and destroy the train.

(Tile Total) * (Longest Train) * (Uniqueness) * (1.50 * Perfect Train Count)

## Modes
---
- Story
- Time Attack
- Battle
  - Online
  - Local

## Story
---
Dom and Mina are enjoying their lives as billed, water adjacent creatures. Little do our heroes suspect that in the forbidden boneyard, an evil plan is being brought to its apex. The Nerfarious Professor Osteo has finished his calcification ray, and has Dominoland in his sights. After he presses the big red button, our heroes see the crackling ray as it sweeps across the land - calcifying themselves and everything around them. Are you a bad enough duck to stop the Boneyard Skeletons from taking over Dominoland?

## Tiles
---
- Mino (Foreground) : most important tile, has a value of 0-6 and can be combined with other Minos via Bars
- Ice (Background) : Moving foreground tiles slide 1 tile further
- Web (Background) : Any tile that moves over this one is trapped in place
- Metal : Indestructable
- Tree (Foreground) : Destructable, but immovable obstacle
- Grass : Neutral tile
- Rock : Destructable, can absorb damage 1 time
- Brick : Can absorb damage 2 times

## Levels
---
- Grass Zone (Mina) \ (The Big Bad Wolf)
  - Grass : Neutral Background
  - Fence : Blocking Foreground
  - Bush : Trigger Foreground, play shaking animation and obscure Mino
  - Water : 
- Mine Zone
  - Mine Track : Background, Mine Carts can move on these
  - Mine Cart : Foreground, Collects 1 Mino and stops on the next one
  - Boulder : Blocking Foreground
  - Pit
  - Rocky : Neutral Background
- Mountain Zone
  - Ice
  - Snow
- Beach Zone (Piptopus)
  - Sand
  - Water
  - Coconut
  - Palm Tree
- Chess Zone
- City Zone
  - Crate
- Boneyard Zone (Judge Muggins)
- Osteo Lab Zone (Professor Osteo)
  - Metal Crate

## Heroes
---
- Dom the Duck
  - `Swap` - Swap the current falling Mino with the Mino that is next to fall
- Mina the Platypus
  - `Stash` - Store 1 additional Mino
- Chesster the Chess Piece
  - `Slide` - Move an inert Mino any amount of tiles up, down, left or right
- Tux the Cat

## Villains
---
- Foreman Dwarfman
- Professor Osteo
  - `Calcifier` - Attach 1 Mino to a position on the opponent's next Mino.
- The Big Bad Wolf
  - `Huff & Puff` - Blow away between 0-6 Minos from the board at random
- Judge Muggins
  - `Pound Gavel` - Destroy 1 Mino
- Piptopus
  - `Ink Spray` - Covers the opponent's screen in obscuring ink