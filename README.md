# godot-gdnative-starter

This repo is intended to be a suitable boilerplate for Godot projects utilizing GDNative (C++ bindings).

It may undergo many changes and evolve as we gain a deeper knowledge of the Godot engine, so be sure to keep an eye on this space.

This boilerplate is currently developed under the assumption that you are using the MSVC compiler on a Windows machine, but we may make accomodations for developing on other platforms in the future.

Otherwise, feel free to make the configuration changes necessary to develop on your platform and architecture.

## Prior Reading

---

This README won't be covering any instructions regarding developing a GDNative C++ library itself, so I highly recommend checking out the following documentation:

- [Godot Engine C++ Development](https://docs.godotengine.org/en/3.1/development/cpp/index.html)
- [GDNative C++ Example](https://docs.godotengine.org/en/stable/tutorials/plugins/gdnative/gdnative-cpp-example.html)

## Requirements

---

- Python (3.5 or higher): [Installation](https://www.python.org/downloads/)
- SCons (3.1.1 or higher): [Installation](https://pypi.org/project/SCons/) - [Docs](https://scons.org/documentation.html)
- Visual Studio Code: [Installation](https://code.visualstudio.com/)
- C/C++ VSCode Extension: [Installation](https://code.visualstudio.com/docs/languages/cpp)

## Generating Bindings

---

- Clone the repository via `git clone https://github.com/Storm-Sphere-Studios/godot-gdnative-starter.git`
- cd into `godot-cpp`
- Refer to the instructions below to generate bindings for each platform and target

### Windows (x64)

- Debug: `scons platform=windows generate_bindings=yes -j <threads>`
- Release: `scons platform=windows generate_bindings=yes target=release -j <threads>`

### Linux (x64)

- Debug: `scons platform=linux generate_bindings=yes -j <threads>`
- Release: `scons platform=linux generate_bindings=yes target=release -j <threads>`

### Mac OSX (x64)

- Debug: `scons platform=osx generate_bindings=yes -j <threads>`
- Release: `scons platform=osx generate_bindings=yes target=release -j <threads>`

Take note of the `-j` option, you can specify the number of CPU threads to use to drastically speed up the build time. You can typically set this to the same amount of cores pertaining to your processor without running into any issues. Of course, this is entirely optional and you can happily omit the option, but it's highly recommended that you don't, unless you were brewing a coffee or trying to run out the clock at work anyway (PSA: Don't do that).

## Setting up the VSCode Project

---

With VSCode and the C/C++ Extension installed, open the repo directory in VSCode.

Open `.vscode/c_cpp_properties.json`, and confirm that the `compilerPath` key points to your compiler executable, be sure to update it if not.

## Developing your GDNative Library

---

All source files for your GDNative library are contained in `NativeLib/src` by default. It's important to keep all cpp source files within this folder structure, as the SCons build configuration depends on it. Otherwise, if you must make changes, be sure to update `SConstruct` to point to the new directory with your source files:

_SConstruct_

```python
line 65: add_sources(sources, "NativeLib\\new\\path\\to\\src")
```

### Building the library

In order to build your new GDNative library in order to use it in Godot, you can easily do so via the pre-made VSCode tasks included in the repo.

Open `terminal > Run Task...`, and you will see a list of tasks to generate a Debug or Release build for the Windows, MacOSX and Linux 64-bit platforms:

![tasks image](https://i.ibb.co/Tknd6Qz/tasks.png)

Simply execute the task(s) that corresponds to the platform you wish to build your library for, and the desired target. Once completed, the library files will be outputted to the following directories, depending on the platform chosen:

- Windows: `Godot/bin/win64`
- Linux: `Godot/bin/linux`
- MacOSX: `Godot/bin/osx`

Refer to this section of the GDNative C++ [documentation](https://docs.godotengine.org/en/stable/tutorials/plugins/gdnative/gdnative-cpp-example.html#using-the-gdnative-module) in regards to loading your new library in Godot.

More platforms will eventually be supported as this boilerplate evolves, but if you need to support a platform other than the ones listed, you will need to update `SConstruct`, and then add your new platform build task to `.vscode/tasks.json`.
