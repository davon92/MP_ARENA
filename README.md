# MP_ARENA

# Master Blaster

*A third-person, grid-based action game inspired by Bomberman where players drop bombs, collect power-ups, and outsmart AI enemies.*

---

## 🎯 Project Purpose

**Master Blaster** is a personal project designed to demonstrate expert-level gameplay programming skills using Unreal Engine 5.4.  
The goal is to build a polished, modular, and scalable game architecture that mirrors the standards and expectations of AAA studios.

This project serves as a portfolio piece to showcase my readiness for Senior Gameplay Programmer roles in the industry, covering everything from core systems to performance optimization and debugging workflows.

---

## 🔧 Tech Stack

- **Engine:** Unreal Engine 5.4
- **Language:** C++
- **IDE:** JetBrains Rider
- **Version Control:** Git + GitHub Projects
- **Optional Tools:** Figma (UI/UX planning), Unreal Insights (profiling)

---

## 🕹️ DataStrucures (Planned & In Progress)

> ✅ = Complete | 🔄 = In Progress | 📝 = Planned

| Feature | Status | Description |
|--------|--------|-------------|
| Stack | 🔄 | |

## 🚀 Getting Started

> For Unreal Developers familiar with GitHub

1. Clone the repo:
2. Open `.uproject` in Unreal Engine 5.4
3. Build project in Rider or VS2022
4. Run the editor and explore the `DevMap`

---

## 📚 Devlogs / Docs

Starting with a first assessment of the system my goal is to work from Application Start to Application Exit Here is how i plan to structue the approach

> ✅ = Complete | 🔄 = In Progress | 📝 = Planned

| Step | Lesson | Unreal API / Pattern |
|--------|--------|-------------|
| ✅ App Launch |	Understand what runs first (GameInstance, Subsystems)	| UGameInstance, UGameInstanceSubsystem |
| ✅ Subsystem Boot |	Create a UMasterMessageSubsystem or UGameEventSubsystem as your core message hub	| UGameInstanceSubsystem |
| 📝 Main Menu Entry (Optional) |	Load a title screen, or jump straight into the DevMap	| UUserWidget, Level Blueprint |
| 📝 First Map Load |	Use GameMode + GameState + PlayerController as system roots	| AGameModeBase, AGameStateBase, APlayerController |
| ✅ Core Services Online |	Boot input handling, grid manager, bomb manager, debug tool manager	| Custom Subsystems, Managers |
| ✅ Player Pawn Spawned |	Set up enhanced input, character components, ability slots | ACharacter, UEnhancedInputComponent |
| 📝 Gameplay Loop | Run the match — spawn bombs, power-ups, kill AI, etc.	| Custom gameplay logic |
| 📝 Win/Loss Conditions |	Implement game end state, messaging, UI popups |	AGameState, OnMatchEnd() |
| 📝 Return to Menu / Exit	| Cleanup, destroy subsystems, prepare for exit	| ShutdownModule, Deinitialize() |

## 🧑‍💻 About the Developer

Hi, I’m Davon Allen, a gameplay engineer with a focus on building high-quality, scalable gameplay systems.  
My goal is to join a AAA studio as a Mid - Senior Gameplay Programmer and contribute to systems that drive player creativity, fun, and depth.

- [LinkedIn](https://www.linkedin.com/in/davonaallen/)
- [Portfolio](https://www.davonallen.com/)
- [Vimeo](https://vimeo.com/davonaallen)

---
