# Fract-ol Explorer

This project is a fractal exploration program created using the MiniLibX graphics library. It allows users to navigate and zoom into various fractal sets, including Mandelbrot, Julia, and the Burning Ship. The application features interactive, mouse-centric zooming and a variety of other controls for an immersive experience.

## Features

*   **Multiple Fractals:** Explore the Mandelbrot set, the Julia set, and the Burning Ship fractal.
*   **Interactive Mouse Zoom:** Zoom in and out of the fractals, with the mouse cursor's position acting as the precise epicenter of the zoom. This allows for intuitive and detailed exploration.
*   **Dynamic Navigation:** Pan the view across the fractal using the arrow keys.
*   **Customizable Parameters:**
    *   Adjust the number of iterations to increase or decrease the detail of the fractal.
    *   Modify the parameters of the Julia set in real-time.
*   **Color Palettes:** Cycle through several vibrant color palettes to change the aesthetic of the fractals.

## How It Works: The Zoom Mechanism

The core of the interactive experience is the mouse-centric zoom. Here’s a breakdown of how it was implemented:

1.  **Mouse Position to Complex Plane:** When the user triggers a zoom (via the mouse wheel), the program first captures the mouse's pixel coordinates (`x`, `y`). These coordinates are then translated into a point in the complex plane (`mouse_re`, `mouse_im`) that corresponds to the cursor's location within the current view.

2.  **Y-Axis Inversion:** A key detail is that graphics libraries like MiniLibX often have their origin at the top-left corner, while the complex plane's imaginary axis typically increases upwards. The calculation correctly inverts the y-coordinate to account for this difference: `(win_y - mouse_y)`.

3.  **Calculating the New View:** Instead of simply scaling the existing view boundaries (which leads to floating-point precision errors at high zoom levels), the new implementation calculates the new boundaries directly.
    *   It determines the new range of the real and imaginary axes by scaling the current range by a `zoom_factor`.
    *   It calculates the mouse's relative position within the window (from 0.0 to 1.0 on each axis).
    *   Finally, it sets the new `min_val` and `im_min` by positioning the `mouse_re` and `mouse_im` point at the same relative position within the new, smaller (or larger) view.

This method ensures that the point directly under the mouse cursor remains stationary during the zoom, creating a precise and intuitive user experience, even at extreme magnification levels.

## Our Development Journey

Achieving the perfect zoom was an iterative process:

1.  **Initial Implementation:** The first zoom was basic, always targeting the center of the window.
2.  **First Attempt at Mouse-Centric Zoom:** The initial logic for mouse-based zooming was flawed, primarily because it didn't correctly handle the inverted y-axis of the graphics coordinate system.
3.  **Addressing Precision and "Feel":** Subsequent iterations focused on improving the user experience. We increased the `zoom_factor` for a more noticeable effect and switched to `long double` for calculations to combat precision loss. However, artifacts at high zoom levels persisted.
4.  **The Breakthrough:** The final, successful implementation involved a complete re-architecture of the zoom logic. By directly recalculating the view boundaries based on the mouse's relative position rather than interpolating from the old boundaries, we eliminated the cumulative precision errors. This provided the robust, accurate, and intuitive zoom that is in the final version.

## How to Use

### Prerequisites

*   A C compiler (e.g., `gcc`)
*   The `make` utility
*   The MiniLibX library (included in the `mlx` directory)

### Compilation

To compile the program, run the `make` command in the root directory:

```bash
make
```

### Running the Application

Execute the program from the command line, specifying which fractal you want to view.

**For the Mandelbrot set:**
```bash
./fractol mandle
```

**For the Julia set:**
```bash
./fractol julia
```

**For the Burning Ship fractal:**
```bash
./fractol ship
```

### Controls

| Key(s)              | Action                                        |
| ------------------- | --------------------------------------------- |
| **Mouse Wheel**     | Zoom in and out (centered on the mouse)       |
| **Arrow Keys**      | Pan/move the view of the fractal              |
| **Z / X**           | Zoom in or out (centered on the window)       |
| **I / O**           | Increase / Decrease the number of iterations  |
| **1, 2, 3, 4, 5**   | Change the color palette                      |
| **P**               | Rotate through the current color palette      |
| **N**               | (In Julia set) Toggle mouse-based parameter modification |
| **W, A, S, D**      | (In Julia set) Modify the C1/C2 parameters    |
| **H**               | Toggle the on-screen help menu                |
| **ESC**             | Exit the program                              |

