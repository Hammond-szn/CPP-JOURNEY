CGPA Calculator Web UI

This folder provides a simple static web UI that replicates the behavior of the C++ program cgpacal.cpp in the project root.

Files
- index.html — the single-page UI.
- style.css — styles for the UI.
- app.js — JavaScript implementing the same formula as cgpacal.cpp.

How to use
1. Open web-ui/index.html in any modern browser.
2. Enter four CGPA values (level 100, 200, 300, 400) and click "Calculate CGPA".

Formula used
CGPA = (cgpa1 + cgpa2 + cgpa3 * 2 + cgpa4 * 2) / 6

Optional: run the real C++ program in the browser (advanced)
- Install Emscripten (emsdk) and activate toolchain.
- Compile the program with: emcc "../cgpacal.cpp" -s WASM=1 -o cgpacal.html -O2
- The generated output will include cgpacal.js and cgpacal.wasm which can be integrated or loaded into this page.

If you want, I can:
- Add an option to compile/pack the C++ into WASM and wire it into the page (requires emscripten installed locally).
- Build a small local backend to run the existing cgpacal.exe (less safe) and expose results via HTTP.

Note: This UI intentionally replicates the program logic in JavaScript so it can be tested in a browser without additional toolchain requirements.