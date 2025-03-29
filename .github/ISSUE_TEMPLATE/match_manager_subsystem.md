---
name: Match Manager Subsystem
about: Manage round lifecycle: start, win/loss, reset
title: "[GameFlow] MatchManagerSubsystem"
labels: match, systems, gameflow, phase-4
assignees: 
---

## Description

Create a subsystem that manages the lifecycle of a match: startup, round timer, win/loss condition, and reset.

---

## Tasks

- [ ] Create UMatchManagerSubsystem  
- [ ] Start countdown on match begin  
- [ ] Monitor player deaths and win conditions  
- [ ] Reset round state after match ends  

---

## Dependencies

- [ ] GameMode, GameState, PlayerController ready  
- [ ] GameEventSubsystem for signaling  

---

## Acceptance Criteria

- [ ] Match starts and ends predictably  
- [ ] Win/loss triggers event broadcasts  
