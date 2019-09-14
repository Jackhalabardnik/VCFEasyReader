.PHONY: clean All

All:
	@echo "----------Building project:[ VCFEasyReader - Release ]----------"
	@cd "VCFEasyReader" && "$(MAKE)" -f  "VCFEasyReader.mk"
clean:
	@echo "----------Cleaning project:[ VCFEasyReader - Release ]----------"
	@cd "VCFEasyReader" && "$(MAKE)" -f  "VCFEasyReader.mk" clean
