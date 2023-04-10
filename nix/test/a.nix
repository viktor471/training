with import <nixpkgs> {};

let
  myScript = pkgs.writeShellScriptBin "helloWorld" "echo Hello World";
in
stdenv.mkDerivation rec {
  name = "test-environment";
  src = myScript

  # buildInputs = [ myScript ];
}