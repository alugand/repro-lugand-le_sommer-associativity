# shell.nix (simple, no pinning yet)
let
  pkgs = import ./nixpkgs-pin.nix {};
in
pkgs.mkShell {
  buildInputs = [
    pkgs.gcc
  ];
}
