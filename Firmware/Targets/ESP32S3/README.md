okay

okay lets get started

to build you need

a computer

an ide

and esp idf v5.4.1 installed

for autocompletion install esp-clangd with
idf_tools.py install esp-clangd

original clangd has some issues idk why

with zed this is my project config:

{
  "lsp": {
    "clangd": {
      "path_lookup": true,
      "binary": {
        "path": "/home/orhan/.espressif/tools/esp-clang/esp-18.1.2_20240912/esp-clang/bin/clangd",
        "arguments": [
          "--header-insertion=never",
          "--query-driver=**",
          "--log=verbose",
          "--compile-commands-dir=/home/orhan/github/OpenFFBoard/Firmware/Targets/ESP32S3/build"
        ]
      }
    }
  }
}
