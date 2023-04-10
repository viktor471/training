with import <nixpkgs> {};
stdenv.mkDerivation {
  name = "my-app";
  src = ./.;

  buildInputs = [ boost ];

  buildPhase = "c++ -o a a.cpp -lboost_system";

  installPhase = ''
    mkdir -p $out/bin
    cp a $out/bin/
  '';
}
