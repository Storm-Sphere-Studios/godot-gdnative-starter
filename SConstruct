import os

# platform= makes it in line with Godots scons file, keeping p for backwards compatibility
platform = ARGUMENTS.get("p", "linux")
platform = ARGUMENTS.get("platform", platform)
target_arch = ARGUMENTS.get('a', ARGUMENTS.get('arch', '64'))
godot_bin_folder = ARGUMENTS.get("godot_folder", "Godot\\bin")

# This makes sure to keep the session environment variables on windows, 
# that way you can run scons in a vs 2017 prompt and it will find all the required tools
env = Environment()
if platform == "windows":
    env = Environment(ENV = os.environ)

godot_headers_path = "godot-cpp\\godot_headers"
godot_bindings_path = "godot-cpp"
output_folder = ""

# default to debug build, must be same setting as used for cpp_bindings
target = ARGUMENTS.get("target", "debug")

platform_suffix = '.' + platform + '.' + target + '.' + target_arch

if ARGUMENTS.get("use_llvm", "no") == "yes":
    env["CXX"] = "clang++"

# put stuff that is the same for all first, saves duplication 
if platform == "osx":
    env.Append(CCFLAGS = ['-g','-O3', '-std=c++14', '-arch', 'x86_64'])
    env.Append(LINKFLAGS = ['-arch', 'x86_64', '-framework', 'Cocoa', '-Wl,-undefined,dynamic_lookup'])
    platform_suffix = ''
    output_folder = "osx"
elif platform == "linux":
    env.Append(CCFLAGS = ['-g','-O3', '-std=c++14', '-Wno-writable-strings'])
    env.Append(LINKFLAGS = ['-Wl,-R,\'$$ORIGIN\''])
    output_folder = "linux"
elif platform == "windows":
    # need to add detection of msvc vs mingw, this is for msvc...
    env.Append(LINKFLAGS = ['/WX'])
    output_folder = "win64"
    if target == "debug":
        env.Append(CCFLAGS = ['-EHsc', '-D_DEBUG', '/MDd'])
    else:
        env.Append(CCFLAGS = ['-O2', '-EHsc', '-DNDEBUG', '/MD'])

def add_sources(sources, dir):
    for f in os.listdir(dir):
        if f.endswith(".cpp"):
            sources.append(dir + "/" + f)

def add_suffix(libs):
    return [lib + platform_suffix for lib in libs]


def get_output_path():
  return '{0}\\{1}\\{2}'.format(godot_bin_folder, output_folder, "NativeLib")


env.Append(CPPPATH=[godot_headers_path, godot_bindings_path + '/include/', godot_bindings_path + '/include/core/', godot_bindings_path + '/include/gen'])

env.Append(LIBS=add_suffix(['libgodot-cpp']))
env.Append(LIBPATH=[ godot_bindings_path + '/bin/' ])

sources = []
add_sources(sources, "NativeLib\\src")

library = env.SharedLibrary(target=get_output_path(), source=sources)
Default(library)