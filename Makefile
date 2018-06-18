TARGET           = Diffuser.out
OBJECT_01        = main.o
SOURCE_01        = main.cpp

$(TARGET): $(OBJECT_01)
	         g++ -g --enable-checking -o $(TARGET) $(OBJECT_01) -lstdc++ 
		 @echo Make done

$(OBJECT_01) : $(SOURCE_01) 
	         g++ -g -c $(SOURCE_01) -o $(OBJECT_01)

clean :
	rm -f $(TARGET)  $(OBJECT_01)
	@echo Clean done
