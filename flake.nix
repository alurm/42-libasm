{
  inputs.nixpkgs.url = "github:nixos/nixpkgs/79b3d4bcae8c7007c9fd51c279a8a67acfa73a2a";
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
    devShells.${system}.default = pkgs.mkShell {
      packages = [pkgs.nasm];
    };
  };
}
