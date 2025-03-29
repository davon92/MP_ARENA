---
name: Bomb Placement Logic
about: Handle bomb spawning based on player input and grid position
title: "[Gameplay] Bomb Placement System"
labels: gameplay, bomb, phase-2
assignees: 
---

## Description

Implement logic to allow the player to place bombs at their current grid-aligned position, respecting any placement limits.

---

## Tasks

- [ ] Determine player’s current tile position  
- [ ] Prevent placing multiple bombs in the same spot  
- [ ] Enforce max active bombs per player  
- [ ] Interface with GridManager to mark tile as occupied  

---

## Dependencies

- [ ] Bomb Component for detonation behavior  
- [ ] GridManagerSubsystem for valid placement checks  

---

## Acceptance Criteria

- [ ] Bombs spawn only on valid tiles  
- [ ] Player cannot exceed max allowed bombs  
- [ ] No overlapping or misplaced bombs  
