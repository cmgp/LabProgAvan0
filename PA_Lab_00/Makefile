
ifndef verbose
  SILENT = @
endif

.PHONY: clean $(PROJECTS) run

PA_Lab_01:
	@echo "–––– Compilando PA_Lab_00 ––––"
	@${MAKE} --no-print-directory -f PA_Lab_00.make

run:
	@${MAKE} --no-print-directory -f PA_Lab_00.make run

clean:
	@${MAKE} --no-print-directory -f PA_Lab_00.make clean
