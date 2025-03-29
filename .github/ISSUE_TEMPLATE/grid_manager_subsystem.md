---
name: Grid Manager Subsystem
about: Manage the destructible grid-based game world
title: "[Core] UGridManagerSubsystem"
labels: systems, grid, phase-1
assignees: 
---

## Description

Create a grid system that defines the structure of the level — destructible tiles, spawn locations, and power-up placement.

---

## Tasks

- [ ] Create `UGridManagerSubsystem`  
- [ ] Define grid size, tile spacing, and origin  
- [ ] Add ability to convert world → tile index  
- [ ] Mark tiles as occupied/unoccupied  
- [ ] Visualize grid with debug overlay  

---

## Dependencies

- [ ] DevToolsSubsystem for overlay  
- [ ] Destructible tiles system  

---

## Acceptance Criteria

- [ ] Grid can be generated and queried  
- [ ] Systems can interact with grid positions reliably  
