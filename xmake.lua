add_requires("freeglut", "stb", "miniaudio")

target("aedes_attack")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("include")
    set_targetdir("$(projectdir)/bin")
    add_packages("freeglut", "stb", "miniaudio")
