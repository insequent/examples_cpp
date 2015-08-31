Mesos Test-bed
--------------

NOTE: Libraries based of mesos git tag 0.24.0-RC1

NOTE: To run generated binaries, testers will have to set ``LD_LIBRARY_PATH``. For example::

    LD_LIBRARY_PATH=`pwd`/lib/ ./example

    OR

    export LD_LIBRARY_PATH=`pwd`/lib/
    ./example

Building and testing Mesos can take an incredible amount of time, thus a place to run
quick test scripts or full on libraries using Mesos's bundled libraries is nice to have.
That is the goal of this particular directory.

- ``Dockerfile`` - A build environment that will generate the libraries (must be editted if versions change)
- ``include`` and ``lib`` - The generated libraries generated from Mesos's git repo
- ``Makefile`` - Edit this at will. A simple makefile used for compiling example.cpp
