---
name: Game Event Subsystem
about: Global messaging/event system for decoupling gameplay logic
title: "[Core] UGameEventSubsystem"
labels: systems, messaging, phase-1
assignees: 
---

## Description

Create a global message bus using `UGameInstanceSubsystem` to broadcast and listen for gameplay events between systems.

---

## Tasks

- [ ] Create `UGameEventSubsystem`  
- [ ] Add basic event definitions (e.g., `OnPlayerKilled`, `OnPowerupCollected`)  
- [ ] Add delegate signatures  
- [ ] Add global getter: `GetGameInstance()->GetSubsystem<UGameEventSubsystem>()`  
- [ ] Test with a simple broadcast in DevMap  

---

## Dependencies

None  

---

## Acceptance Criteria

- [ ] Any system can subscribe and broadcast events  
- [ ] Events fire properly with payloads if needed  
