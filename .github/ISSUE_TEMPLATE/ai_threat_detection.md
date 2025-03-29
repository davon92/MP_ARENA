---
name: AI Threat Detection
about: Detect bombs and respond with fleeing behavior
title: "[AI] Threat Detection and Fleeing"
labels: ai, enemies, bomb, phase-3
assignees: 
---

## Description

Implement threat detection logic so AI bots can recognize bombs and flee from blast zones before detonation.

---

## Tasks

- [ ] Poll for nearby bombs with timers  
- [ ] Check if AI is in current or future blast range  
- [ ] Flee to nearest safe tile (integrate with BT)  

---

## Dependencies

- [ ] Behavior Tree and Blackboard  
- [ ] Bomb Component with blast prediction logic  

---

## Acceptance Criteria

- [ ] AI attempts to flee before bombs explode  
- [ ] Fleeing behavior is consistent and believable  
