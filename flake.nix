{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { nixpkgs, flake-utils, ... }@inputs:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = nixpkgs.legacyPackages.${system};

      in {
        devShell = pkgs.mkShell {
          buildInputs = with pkgs; [ gcc14 ];
          shellHook = ''
            alias run="clang++ -std=c++2b main.cpp -o main && ./main"
          '';
        };

      });

}
