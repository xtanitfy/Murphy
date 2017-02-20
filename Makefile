all:
	$(MAKE) -C src	  all
	$(MAKE) -C test          all
	$(MAKE) -C examples          all
	
clean:
	$(MAKE) -C src        clean	
	$(MAKE) -C test          clean
	$(MAKE) -C examples          clean
