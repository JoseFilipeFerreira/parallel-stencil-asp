#!/bin/sh

#PBS -N AP_stencil2D
#PBS -l walltime=2:00:00
#PBS -l nodes=1:r641:ppn=16
#PBS -q mei

module load gcc/7.2.0

cd $PBS_O_WORKDIR

make

echo "Stencil threads: 16"
export OMP_NUM_THREADS=16
./stencil2D

echo "Stencil threads: 32"
export OMP_NUM_THREADS=32
./stencil2D

echo "Asp threads: 16"
export OMP_NUM_THREADS=16
./asp

echo "Asp threads: 32"
export OMP_NUM_THREADS=32
./asp

make clean
