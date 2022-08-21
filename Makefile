all: src

.PHONY: src

src:
	$(MAKE) -C src all

# Builder will call this to install the application before running.
install: src
	echo "Installing is not supported"

# Builder uses this target to run your application.
run: src
	chmod +x build/packager
	build/packager

clean:
	$(MAKE) -C src clean
