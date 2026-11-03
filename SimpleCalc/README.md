# Simple Calculator — iOS App (C++ core + SwiftUI)

You need a **Mac** with **Xcode** installed (free from the Mac App Store) to build this.
You do **not** need a paid Apple Developer account to run it on your own iPhone —
a free Apple ID is enough, the app just needs re-signing every 7 days.

## What's in this folder

| File | Purpose |
|---|---|
| `Calculator.hpp` / `Calculator.cpp` | The actual calculator logic, plain C++ |
| `CalculatorWrapper.h` / `CalculatorWrapper.mm` | Objective-C++ glue — lets Swift call the C++ code |
| `SimpleCalc-Bridging-Header.h` | Tells Swift where to find the wrapper |
| `ContentView.swift` | The calculator screen (buttons, display) |
| `SimpleCalcApp.swift` | The app's entry point |

## Step 1 — Create the Xcode project

1. Open **Xcode** → **File → New → Project**
2. Choose **iOS → App** → Next
3. Product Name: `SimpleCalc`
4. Interface: **SwiftUI**, Language: **Swift**
5. Save it anywhere you like

## Step 2 — Remove the placeholder files

Xcode auto-creates its own `ContentView.swift` and `SimpleCalcApp.swift`.
Delete those two (Move to Trash) — you'll replace them with the ones here.

## Step 3 — Add all the files from this folder

1. In Xcode's file navigator (left sidebar), right-click the `SimpleCalc` group → **Add Files to "SimpleCalc"...**
2. Select all 7 files from this folder and add them
3. **Important:** as soon as you add `CalculatorWrapper.mm` (a C++/Obj-C file), Xcode will pop up:

   > "Would you like to configure an Objective-C bridging header?"

   Click **Create Bridging Header** — yes, even though we already gave you one.
   Then: delete the empty one Xcode just made, and instead go to
   **Build Settings** (select the SimpleCalc target) → search **"Bridging Header"** →
   set **Objective-C Bridging Header** to:
   ```
   SimpleCalc/SimpleCalc-Bridging-Header.h
   ```

## Step 4 — Run it

- **On the Simulator**: pick any iPhone simulator from the device dropdown at the top, press ▶️ (Cmd+R)
- **On your real iPhone**:
  1. Plug your iPhone into the Mac (or use Wi-Fi debugging)
  2. Select your iPhone from the device dropdown
  3. Xcode → Settings → Accounts → add your Apple ID if you haven't
  4. Back in the project settings → **Signing & Capabilities** → check **Automatically manage signing**, pick your Apple ID as the Team
  5. Press ▶️. First run, your iPhone will refuse to open it —
     go to **Settings → General → VPN & Device Management** on the iPhone,
     trust your developer profile, then relaunch the app

That's it — you'll have a Calculator icon on your home screen. With a free account
you'll need to redo this every 7 days (Apple's limit on free signing); a paid
$99/yr developer account removes that limit and lets you install via TestFlight instead.

## How it works, briefly

- `Calculator.cpp` does the actual arithmetic — totally portable C++, no Apple APIs.
- `CalculatorWrapper.mm` is Objective-C++, the only file allowed to `#include` both
  a C++ header and an Objective-C header at once. It owns one `Calculator` instance
  and exposes plain methods.
- Swift can't see C++ directly, but it *can* see Objective-C classes through the
  bridging header — so `ContentView.swift` just calls `CalculatorWrapper()` like
  any normal Swift object.
