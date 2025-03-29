---
name: Player Death Handler
about: Detect and respond to player death in gameplay
title: "[GameFlow] Player Death Handling"
labels: player, gameflow, systems, phase-4
assignees: 
---

## Description

Detect when a player is caught in a blast and trigger appropriate death response: UI, removal, event broadcast.

---

## Tasks

- [ ] Implement overlap/collision detection with blast  
- [ ] Trigger death animation/effect  
- [ ] Inform GameEventSubsystem of death  
- [ ] Remove player from match if lives = 0  

---

## Dependencies

- [ ] Bomb Component with blast logic  
- [ ] MatchManagerSubsystem  

---

## Acceptance Criteria

- [ ] Player dies on contact with blast  
- [ ] Player is removed from active play state  
