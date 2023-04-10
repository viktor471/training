{func = builtins.readFile ./hello.sh;}
# func = x: ''echo ${x}'';
# my-script = (pkgs.writeScriptBin my-name my-src).overrideAttrs(old: {
  # buildCommand = "${old.buildCommand}\n patchShebangs $out";
# });