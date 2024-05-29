add_requires("freeglut")

target("aedes_attack")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("include")
    set_targetdir("$(projectdir)/bin")
    add_packages("freeglut")
