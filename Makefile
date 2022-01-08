

run-m1:
	gcc -Wall source/module_1/module_1.c source/utils/utils.c -I source/utils  -o results/m1
	./results/m1

run-m2:
	gcc -Wall source/module_2/module_2.c source/utils/utils.c -I source/utils  -o results/m2
	./results/m2

run-m3:
	gcc -Wall source/module_3/module_3.c source/utils/utils.c -I source/utils  -o results/m3
	./results/m3

run-m4:
	gcc -Wall source/module_4/module_4.c source/utils/utils.c -I source/utils  -o results/m4
	./results/m4

run-m5:
	gcc -Wall source/module_5/module_5.c source/utils/utils.c -Isource/utils  -o results/m5
	./results/m5

run-m6:
	gcc -Wall source/module_6/module_6.c source/utils/utils.c -Isource/utils  -o results/m6
	./results/m6

run-m7:
	gcc -Wall source/module_7/module_7.c source/utils/utils.c -Isource/utils  -o results/m7
	./results/m7

run-all:
		make run-m1
		make run-m2
		make run-m3
		make run-m4
		make run-m5
		make run-m6
