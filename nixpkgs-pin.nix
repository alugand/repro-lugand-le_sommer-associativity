# nixpkgs-pin.nix — picks a specific snapshot of nixpkgs
let
  rev = "b134951a4c9f3c995fd7be05f3243f8ecd65d798";     # choose a nixpkgs commit (e.g., from the stable 24.05 branch)
  sha256 = "0zydsqiaz8qi4zd63zsb2gij2p614cgkcaisnk11wjy3nmiq0x1s";  # a safety checksum; Nix tells you the right value on first run
in
import (builtins.fetchTarball {
  url = "https://github.com/NixOS/nixpkgs/archive/${rev}.tar.gz";
  inherit sha256;
})
