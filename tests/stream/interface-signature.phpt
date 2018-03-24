--TEST--
Test that the Stream interface exists and has correct number of required methods
--FILE--
<?php
var_dump(interface_exists(\Stream::class));
\ReflectionClass::export(\Stream::class);
--EXPECTF--
bool(true)
Interface [ <internal:streams2> interface Stream ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [13] {
    Method [ <internal:streams2, ctor> abstract public method __construct ] {

      - Parameters [3] {
        Parameter #0 [ <required> string $uri ]
        Parameter #1 [ <required> string $mode ]
        Parameter #2 [ <optional> Stream\Context or NULL $context ]
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
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method read ] {

      - Parameters [1] {
        Parameter #0 [ <optional> int%S $maxbytes ]
      }
      - Return [ string ]
    }

    Method [ <internal:streams2> abstract public method write ] {

      - Parameters [1] {
        Parameter #0 [ <required> string $data ]
      }
      - Return [ int%S ]
    }

    Method [ <internal:streams2> abstract public method flush ] {

      - Parameters [0] {
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method close ] {

      - Parameters [0] {
      }
      - Return [ void ]
    }

    Method [ <internal:streams2> abstract public method seek ] {

      - Parameters [2] {
        Parameter #0 [ <required> int%S $pos ]
        Parameter #1 [ <optional> int%S $whence ]
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method isSeekable ] {

      - Parameters [0] {
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method stat ] {

      - Parameters [0] {
      }
    }

    Method [ <internal:streams2> abstract public method setOption ] {

      - Parameters [2] {
        Parameter #0 [ <required> int%S $option ]
        Parameter #1 [ <required> $value ]
      }
      - Return [ bool%S ]
    }

    Method [ <internal:streams2> abstract public method getStream ] {

      - Parameters [0] {
      }
      - Return [ Stream ]
    }
  }
}
