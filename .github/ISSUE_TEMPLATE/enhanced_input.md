---
name: Enhanced Input Setup
about: Implement UE5 Enhanced Input system and bindings
title: "[Input] Enhanced Input Setup"
labels: input, player, phase-2
assignees: 
---

## Description

Implement Unreal Engine 5's Enhanced Input system to support context-aware and configurable player input.

---

## Tasks

- [ ] Define Input Actions for movement, bomb placement, interaction  
- [ ] Create and assign Input Mapping Contexts  
- [ ] Integrate Enhanced Input into PlayerController or Pawn  
- [ ] Ensure input works for both keyboard/mouse and gamepad  

---

## Dependencies

- [ ] PlayerCharacter must exist to bind inputs to  
- [ ] DevToolsSubsystem (optional for debugging input contexts)  

---

## Acceptance Criteria

- [ ] Player input responds as expected for all control schemes  
- [ ] Input system can be expanded or changed easily  
- [ ] All bindings work in DevMap  
