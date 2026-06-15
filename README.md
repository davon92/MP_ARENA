# MP_ARENA: Master Blaster

Third-person Unreal Engine gameplay prototype inspired by Bomberman: players place bombs, interact with a grid-based level, collect power-ups, and use debug tools to inspect gameplay systems while the project grows.

## Portfolio Focus

This repository is an in-progress Unreal C++ gameplay systems prototype. It is meant to show how I break down gameplay architecture, build reusable systems, expose gameplay behavior to Blueprints, and document a path from prototype code toward a stronger portfolio-ready vertical slice.

The current focus is not visual polish. The focus is systems work:

- GameInstance subsystem architecture
- event broadcasting and gameplay messaging
- modular bomb placement and explosion logic
- grid/tile interaction foundations
- data-oriented power-up effects
- developer/debug UI hooks
- player controller, HUD, and character integration

## Current Technical Highlights

| Area | Status | Evidence |
|---|---:|---|
| Gameplay event subsystem | Implemented | `UGameEventSubsystem` exposes Blueprint-assignable gameplay events for player death and power-up collection. |
| Bomb component | Implemented | `UBombComponent` handles countdown, explosion timing, affected grid tiles, VFX/audio hooks, and owner cleanup. |
| Grid manager subsystem | In progress | Grid/tile support exists as a foundation for placement, destructible tiles, and future pathfinding. |
| Power-up system | In progress | Power-up actor/effect component structure supports collectible gameplay modifiers. |
| Debug/dev tools | Implemented/In progress | Dev overlay and subsystem classes are present for faster iteration and runtime inspection. |
| UI/HUD integration | In progress | HUD, player stats overlay, and widget classes support feedback and debugging. |

## Why This Project Exists

I am using this project to rebuild and demonstrate Unreal C++ gameplay confidence through small, visible systems. The goal is to turn a prototype into a clear, playable vertical slice that can support gameplay programmer, tools engineer, and technical designer applications.

This project is also a practice space for explaining engineering decisions clearly:

1. What system owns the responsibility?
2. What data needs to be tracked?
3. What events change state?
4. What should be C++ versus Blueprint-facing?
5. What debug tools make the system easier to verify?

## Roadmap To Portfolio-Ready

### Next Vertical Slice Milestone

- Player can place bombs on valid grid tiles.
- Bombs explode after a timer and affect predictable cardinal tiles.
- Destructible tiles respond to explosion tiles.
- Player can collect at least one power-up that modifies bomb behavior.
- Debug overlay shows bomb count, grid coordinate, current power-up state, and recent gameplay events.
- README includes a short gameplay clip or screenshot section.

### Follow-Up Milestones

- Add enemy AI that reacts to bombs and grid hazards.
- Add win/loss state and match reset flow.
- Add data assets for bomb/power-up tuning.
- Add basic performance notes and profiling screenshots.
- Add a short architecture diagram for subsystem ownership.

## Tech Stack

- Unreal Engine 5.4
- C++
- Blueprints for designer-facing hooks and quick iteration
- JetBrains Rider / Visual Studio
- Git and GitHub

## Running The Project

1. Clone the repository.
2. Open `MP_ARENA.uproject` in Unreal Engine 5.4.
3. Generate project files if prompted.
4. Build the project in Rider or Visual Studio.
5. Open the development map and inspect the gameplay/debug systems.

## Key Source Locations

| Path | Purpose |
|---|---|
| `Source/MP_ARENA/Public/GameEventSubsystem.h` | Gameplay event hub exposed to Blueprints. |
| `Source/MP_ARENA/Private/GameEventSubsystem.cpp` | Event broadcast implementation. |
| `Source/MP_ARENA/Public/BombComponent.h` | Bomb behavior component API. |
| `Source/MP_ARENA/Private/BombComponent.cpp` | Countdown, explosion tiles, VFX/audio, and cleanup logic. |
| `Source/MP_ARENA/Public/GridManagerSubsystem.h` | Grid ownership and lookup foundation. |
| `Source/MP_ARENA/Public/PowerUpEffectComponent.h` | Power-up effect structure. |
| `Source/MP_ARENA/Public/DevToolsSubsystem.h` | Runtime/debug tooling foundation. |

## About Me

I am Davon Allen, a gameplay systems engineer focused on Unity, Unreal, UEFN/Verse, production tooling, and data-driven gameplay workflows.

- Portfolio: https://www.davonallen.com/
- LinkedIn: https://www.linkedin.com/in/davonaallen/
- GitHub: https://github.com/davon92
