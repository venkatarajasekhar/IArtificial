.PHONY: clean All

All:
	@echo "----------Building project:[ 8Puzle - Debug ]----------"
	@cd "8Puzle" && "$(MAKE)" -f  "8Puzle.mk"
clean:
	@echo "----------Cleaning project:[ 8Puzle - Debug ]----------"
	@cd "8Puzle" && "$(MAKE)" -f  "8Puzle.mk" clean
