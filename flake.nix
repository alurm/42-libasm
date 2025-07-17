{
  outputs = { nixpkgs, ... }: let
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages.${system};
  in {
    packages.${system}.default = pkgs.stdenv.mkDerivation {
      name = "libasm";
      src = ./.;
      doCheck = true;
      nativeBuildInputs = [pkgs.nasm];
      installPhase = ''
        runHook preInstall

        mkdir -p $out/lib
        cp libasm.a $out/lib

        runHook postInstall
      '';
    };
  };
}
