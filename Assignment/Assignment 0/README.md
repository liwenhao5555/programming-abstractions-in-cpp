# Assignment 0 - NameHash

## Running on Headless Linux

The Stanford library's `console.h` launches a Java graphics backend (`spl.jar`) by default, which crashes on servers without a display.

**Fix:** Set the `NOCONSOLE` environment variable:

```bash
# Per command
NOCONSOLE=true ./NameHash

# Or export once for the session
export NOCONSOLE=true
./NameHash
```

This is a built-in flag in the Stanford library (`platform.cpp`) that skips the Java backend and uses the terminal directly for I/O. It applies to any program that includes `console.h`.

**Note:** Programs requiring actual graphics (`GWindow`, drawing) still need an X11 display (e.g., Xvfb).

**Debugger tutorial:** Completed DebuggerTutorial.pdf using VS Code (Cursor) with `.vscode/launch.json`, not Qt.
