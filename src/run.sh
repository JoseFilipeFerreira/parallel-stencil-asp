#!/bin/sh

#PBS -N AP_stencil2D
#PBS -l walltime=2:00:00
#PBS -l nodes=1:r641:ppn=16
#PBS -q mei

module load gcc/7.2.0

cd "$PBS_O_WORKDIR" || exit

make

export OMP_PROC_BIND=true

for it in 1 2 3 4 5; do
    for n in 16 32; do
        export OMP_NUM_THREADS="$n"
        echo "Stencil threads: $n"
        ./stencil2D

        echo "ASP threads: $n"
        ./asp
    done
done

make clean
