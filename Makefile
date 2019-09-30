.PHONY: clean All

All:
	@echo "----------Building project:[ VCFEasyReaderTest - Release ]----------"
	@cd "VCFEasyReaderTest" && "$(MAKE)" -f  "VCFEasyReaderTest.mk"
clean:
	@echo "----------Cleaning project:[ VCFEasyReaderTest - Release ]----------"
	@cd "VCFEasyReaderTest" && "$(MAKE)" -f  "VCFEasyReaderTest.mk" clean
