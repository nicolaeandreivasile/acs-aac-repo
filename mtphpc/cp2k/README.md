# CP2K Open Source Molecular Dynamics

[CP2K](https://www.cp2k.org/about) is a quantum chemistry and solid state physics software package that can perform atomistic simulations of solid state, liquid, molecular, periodic, material, crystal, and biological systems.

##### Installation

The following steps are specific for Ubuntu 20.04

Step 1:
```
sudo apt-get update
```

Step 2:
```
sudo apt-get install cp2k
```

## Pycp2k (optional)

[PYCP2K](https://github.com/SINGROUP/pycp2k) is a python package providing a dynamic object-oriented interface to CP2K, an atomistic and molecular simulation software.

##### Installation

**Step 1:**
```
sudo pip install pycp2k
```

## Visualization tools

Tools used for visualizing 3D simulations and graphs from the CP2K run.

### VMD (Visual Molecular Dynamics)

VMD is a molecular visualization program for displaying, animating, and analyzing large biomolecular systems using 3-D graphics and built-in scripting.

#### Installation

**Step 1:**
Download "vmd-1.9.4a57.bin.LINUXAMD64-CUDA102-OptiX650-OSPRay185.opengl.tar.gz" archive from the [Official Site](https://www.ks.uiuc.edu/Research/vmd/)

**Step 2:**
Go to the directory where the archive has been downloaded ("~/Downloads/" most of the time)
```
tar -xvf vmd-1.9.4a57.bin.LINUXAMD64-CUDA102-OptiX650-OSPRay185.opengl.tar.gz -C ~/wanted-dir-path/
```

**Step 3:**
Go to the directory where the archive has been extracted. A README with further instructions will be found inside.

##### Usage

One of the outputs of the CP2K simulation is a VMD compatible file (.xyz). VMD can be opened from bash using:
```
vmd
```

From File -> New molecule… open the file with the .xyz extension. Go to Graphics -> Representations.. and change the Drawing Method to VDW. On the VMD shell type the following commands to define the unit cell of the system and wrap the atoms back to their original unit cell.
```
vmd> pbc set { lx ly lz } -all   # where lx, ly, lz are the box measurements
vmd> pbc box
vmd> pbc wrap -all
```

### Gnuplot

Gnuplot is a portable command-line driven graphing utility for Linux, OS/2, MS Windows, OSX, VMS, and many other platforms.

##### Installation

**Step 1:**
```
sudo apt-get update
```

**Step 2:**
```
sudo apt-get install gnuplot
```

##### Usage

We can visualize the .ener file using gnuplot. To open gnuplot, simply run the following command:
```
gnuplot
```

For example, we can compare the potential energy at each step of the simulation by plotting the second and sixth column:
```
gnuplot> plot './h2-1.ener' u 2:6 w lp
```

## Pymatgen (optional)

Pymatgen (Python Materials Genomics) is a robust, open-source Python library for materials analysis.

##### Installation

**Step 1:**
Go to the [Official Site](https://docs.conda.io/en/latest/miniconda.html) for Conda and download the latest version.
Navigate to the directory where the installation script has been downloaded.
```
chmod +x Miniconda3-latest-Linux-x86_64.sh
./Miniconda3-latest-Linux-x86_64.sh
```

**Step 2:**
Create a conda environment for pymatgen
```
conda create --name pymatgen python
conda activate pymatgen
```

**Step 3:**
Install pymatgen
```
conda install --yes numpy scipy matplotlib
pip install pymatgen
```