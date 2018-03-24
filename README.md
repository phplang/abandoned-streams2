# PHP I/O Streams (v2)

[![Build Status](https://travis-ci.org/phplang/streams2.svg?branch=master)](https://travis-ci.org/phplang/streams2)

This PHP extension is a work in progress set of interfaces and implementation of object-based (rather than resource-
based) I/O Streams. The API is intended to fix all things.

## Installation

We're not available on PECL just yet, so for now you'll need to manually install. This assumes you have a basic PHP
build environment set up - if not read up [here](http://www.phpinternalsbook.com/build_system/building_extensions.html).

Once you have your build environment set up, you can clone the repository:

```
$ git clone git@github.com:phplang/streams2.git
```

Then run `phpize` to generate the `configure` script for your PHP environment:

```
$ phpize
```

Then configure the build:

```
$ ./configure --enable-streams2
```

And finally, you can `make` and `make install` (you might need `sudo` to install!):

```
$ make
$ make install
```

You can also run the tests in your environment to veriy everything is working:

```
$ make test
```

## Wiki

Primarily the discussion around this started on the [wiki](https://github.com/phplang/streams2/wiki), where the intended
use case and interfaces are listed. Feedback is welcome!
