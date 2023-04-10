with import <nixpkgs> {};
stdenv.mkDerivation {
  name = "my-app";
  src = ./.;

  buildInputs = [ rapidjson ];

  buildPhase = "c++ -o a a.cpp";

  installPhase = ''
    mkdir -p $out/bin
    cp a $out/bin/
  '';
}
