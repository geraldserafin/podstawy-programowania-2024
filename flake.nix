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
          buildInputs = with pkgs; [ gcc14 cmake ];
          shellHook = ''
            run() {
                if [ -z "$1" ]; then
                    echo "Usage: run <filename.cpp> [args...]"
                    return 1
                fi

                # Get filename without extension
                filename=$(basename "$1" .cpp)
                sourcefile="$1"
                
                # Shift the first argument (the source file) off the list
                shift
                
                # Check if source file exists
                if [ ! -f "$sourcefile" ]; then
                    echo "Error: File $sourcefile not found"
                    return 1
                fi

                # Compile with modern C++ standard
                g++ -std=c++2b "$sourcefile" -o "$filename"
                
                if [ $? -eq 0 ]; then
                    ./"$filename" "$@"
                    rm "$filename"
                else
                    echo "Compilation failed"
                    return 1
                fi
            }
          '';
        };

      });

}
