let
  # This imports the nix package collection,
  # so we can access the `pkgs` and `stdenv` variables
  nixpkgs = import <nixpkgs> {};
  # Make a new "derivation" that represents our shell
  inherit (nixpkgs) stdenv pkgs;

  a = stdenv.mkDerivation rec {
    name = "my-environment";

    unpackPhase = "true";
    installPhase = ''
      echo "out: $out"
      echo "script: $(readlink -f ${script})"
    '';

    # The packages in the `buildInputs` list will be added to the PATH in our shell
    buildInputs = [
      # cowsay is an arbitary package
      # see https://nixos.org/nixos/packages.html to search for more
      pkgs.cowsay
      pkgs.coreutils
    ];

    my_var = "hello";

    script = pkgs.writeShellScriptBin "hello.sh" ''
      echo "hello"
    '';
    out = script;
  };
in a