my-src = builtins.readFile ./simple-script.sh;
my-script = (pkgs.writeScriptBin my-name my-src).overrideAttrs(old: {
  buildCommand = "${old.buildCommand}\n patchShebangs $out";
});