--TEST--
Test that the Stream interface exists and has correct number of required methods
--FILE--
<?php
var_dump(interface_exists(\Stream::class));
\ReflectionClass::export(\Stream::class);
--EXPECTF--
bool(true)
Interface [ <internal:streams2> interface Stream ] {

  - Constants [3] {
    Constant [ public int%s SEEK_SET ] { 0 }
    Constant [ public int%s SEEK_CUR ] { 1 }
    Constant [ public int%s SEEK_END ] { 2 }
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [13] {
    Method [ <internal:streams2, ctor> abstract public method __construct ] {

      - Parameters [2] {
        Parameter #0 [ <required> string $uri ]
        Parameter #1 [ <optional> $context ]
      }
    }

    Method [ <internal:streams2> abstract public method getName ] {

      - Parameters [0] {
      }
      - Return [ string ]
    }

    Method [ <internal:streams2> abstract public method getUri ] {

      - Parameters [0] {
      }
      - Return [ string ]
    }

    Method [ <internal:streams2> abstract public method isOpen ] {

      - Parameters [0] {
      }
      - Return [ bool%s ]
    }

    Method [ <internal:streams2> abstract public method read ] {

      - Parameters [1] {
        Parameter #0 [ <optional> int%s $maxbytes ]
      }
      - Return [ string ]
    }

    Method [ <internal:streams2> abstract public method write ] {

      - Parameters [1] {
        Parameter #0 [ <required> string $data ]
      }
      - Return [ int%s ]
    }

    Method [ <internal:streams2> abstract public method flush ] {

      - Parameters [0] {
      }
      - Return [ bool%s ]
    }

    Method [ <internal:streams2> abstract public method close ] {

      - Parameters [0] {
      }
      - Return [ void ]
    }

    Method [ <internal:streams2> abstract public method seek ] {

      - Parameters [2] {
        Parameter #0 [ <required> int%s $pos ]
        Parameter #1 [ <optional> int%s $whence ]
      }
      - Return [ bool%s ]
    }

    Method [ <internal:streams2> abstract public method isSeekable ] {

      - Parameters [0] {
      }
      - Return [ bool%s ]
    }

    Method [ <internal:streams2> abstract public method stat ] {

      - Parameters [0] {
      }
    }

    Method [ <internal:streams2> abstract public method setOption ] {

      - Parameters [2] {
        Parameter #0 [ <required> int%s $option ]
        Parameter #1 [ <required> $value ]
      }
      - Return [ bool%s ]
    }

    Method [ <internal:streams2> abstract public method getStream ] {

      - Parameters [0] {
      }
      - Return [ Stream ]
    }
  }
}