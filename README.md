# fract-ol
<img src = "https://github.com/shkaya/fract-ol/blob/main/img/mandelbrot.png" width="500" height="450">
※描画ライブラリminilibx-linuxは別途ダウンロードする必要あり

## Overview
I made a program to draw fractol shapes in C language

## Usage

```
git clone https://github.com/shkaya/fract-ol.git
cd fract-ol
make
```
fractol accepts parameters as follows
```
./fractol [type] [param]
```

## type list

### mandelbrot
The Mandelbrot set is given as the set of points C that converge with the following asymptotic formula
```
z_0 = 0, z_n+1 = (z_n)ˆ2 + c
```
exmaple:
```
./fractol mandelbrot
```

### julia
<img src = "https://github.com/shkaya/fract-ol/brob/main/img/julia.png" width="500" height="450">
```
param: [a(double)] [b(double)]
```
The julia set is given as the set of points z_0 that converge with the following asymptotic formula
```
z_n+1 = (z_n)ˆ2 + c, c = a + bi; 
```
exmple:
```
./fractol julia -0.7 0.27015
```

### burningshp
<img src = "https://github.com/shkaya/fract-ol/brob/main/img/burningship.png" width="500" height="450">
The Buriningship set is given as the set of points C that converge with the following asymptotic formula
```
z_0 = 0, z_n+1 = (|z_n|)ˆ2 + |c|
```
exmple:
```
./fractol burningship
```