<div align="center">

# <img src="https://github.com/Grihladin/42-project-badges/blob/main/badges/fract-ole.png" width="150" height="150"> 

</div>

fract-ol([42Heilbronn](https://www.42heilbronn.de/en/) project) - high performance fractal explorer built in C with [MLX42](https://github.com/codam-coding-college/MLX42), featuring real-time rendering, interactive zoom controls, and support for Mandelbrot and Julia sets with optimized multi-threaded calculations.

## ✨ Features

### 🎯 Core Rendering
- **Real-time Fractal Generation** - Fast escape-time algorithms for Mandelbrot and Julia sets
- **Multi-threaded Processing** - 8 parallel threads for optimal performance on multi-core systems
- **Optimized Calculations** - Direct pixel buffer access and pre-calculated scaling factors
- **High Performance** - Aggressive compiler optimizations (-Ofast, -march=native, -flto)

### 🎮 Interactive Controls
- **Real-time Zoom** - Smooth scroll wheel zooming with instant feedback
- **Responsive UI** - Sub-100ms zoom response time for fluid interaction
- **Live Updates** - All changes reflected immediately in the viewport

### 🎨 Supported Fractals
- **Mandelbrot Set** - Classic fractal with infinite zoom capability
- **Julia Sets** - Multiple Julia set variations with custom parameters
- **Preset Fractals** - Beautiful pre-configured fractal patterns:
  - **Octopus** - Intricate tentacle-like patterns
  - **Medusa** - Complex organic structures  
  - **Snowflake** - Crystalline geometric patterns
  - **Galaxy** - Spiral cosmic formations

## 🚀 Quick Start

## 📋 Requirements

### System Requirements
- **OS**: macOS (Intel/Apple Silicon)
- **Homebrew**: Required for dependency management

### Dependencies (Auto-installed)
- **GLFW** - Window management and input handling
- **CMake** - Build system for MLX42
- **MLX42** - Graphics library (included as submodule)
- **ft_printf (my version)** - Custom printf implementation (included as submodule)
- **get_next_line (my version)** - File reading utilities (included as submodule)


### Installation & Usage
```bash
# Clone the repository
git clone https://github.com/Grihladin/42HN-fractal.git
cd 42HN-fractal

# Build and run (dependencies auto-installed)
make

# Display all available fractals and parameter formats
./fract-ol

# Example usage
./fract-ol 6              # Mandelbrot set
./fract-ol 7 -0.7 0.27015 # Julia set with custom parameters
```

## 🎮 Controls

### Mouse Controls
| Control        | Action            |
|:---------------|:------------------|
| **Scroll Up**  | Zoom in (1.2x)    |
| **Scroll Down**| Zoom out (0.8x)   |
| **ESC Key**    | Exit program      |

## 🏗️ Project Structure

```
fract-ol/
├── 📁 source/                   # Core fractal algorithms
│   ├── mandelbrot.c             # Mandelbrot set implementation
│   ├── julia.c                  # Julia set implementation  
│   ├── mlx_fts.c                # MLX42 interface functions
│   ├── utils.c                  # Utility functions
│   ├── presets.c                # Beautiful fractal presets
│   ├── input_validation.c       # Parameter validation
│   └── main.c                   # Main program entry
├── 📁 includes/                 # Header files
│   └── fractol.h                # Main header with optimizations
├── 📁 ft_printf_submodule/      # Custom printf implementation
├── 📁 get_next_line_submodule/  # File reading utilities
├── 📁 MLX42/                    # Graphics library (submodule)
├── 📁 objects/                  # Compiled object files
├── Makefile                     # Optimized build system
└── README.md                    # Project documentation
```

---

### Made with ❤️ by [mratke](https://github.com/Grihladin) - 42 Heilbronn
