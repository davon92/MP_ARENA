---
name: Grid-Aware Movement
about: Implement AI pathfinding that respects grid-based environment
title: "[AI] Grid-Aware Movement System"
labels: ai, movement, grid, phase-3
assignees: 
---

## Description

Create AI movement that aligns with grid-based tile layout and avoids obstacles. Optionally use A* or simple directional logic.

---

## Tasks

- [ ] Ensure AI movement stays snapped to grid  
- [ ] Avoid destructible tiles and active bombs  
- [ ] Optionally implement A* or BFS grid pathing  
- [ ] Visual debug for path trace  

---

## Dependencies

- [ ] GridManagerSubsystem  
- [ ] Enemy pawn with movement logic  

---

## Acceptance Criteria

- [ ] AI navigates grid cleanly without jitter  
- [ ] Avoids occupied or dangerous tiles  
- [ ] Pathfinding debug info works  
