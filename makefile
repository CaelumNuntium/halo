halo: halo.c refraction.c refraction.h
	gcc -O2 halo.c refraction.c -o halo -lm
run: halo
	./halo
	python plt.py
.PHONY: run
