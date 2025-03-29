---
name: Destructible Tile Actor
about: Create a grid-aligned destructible tile for bombs
title: "[Gameplay] Destructible Tile"
labels: environment, grid, phase-1
assignees: 
---

## Description

Build a destructible tile actor that reacts to bomb blasts and supports destruction effects.

---

## Tasks

- [ ] Create `ADestructibleTile` actor  
- [ ] Add health or single-hit destruction logic  
- [ ] Trigger VFX/SFX on destruction  
- [ ] Notify GridManager on destruction  

---

## Dependencies

- [ ] Bomb Component  
- [ ] GridManagerSubsystem  

---

## Acceptance Criteria

- [ ] Tile explodes and disappears on bomb contact  
- [ ] Grid updates tile state accordingly  
