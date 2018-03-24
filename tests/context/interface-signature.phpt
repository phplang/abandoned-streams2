--TEST--
Test that the Stream\Context interface exists and has correct method signatures
--FILE--
<?php
var_dump(interface_exists(\Stream\Context::class));
\ReflectionClass::export(\Stream\Context::class);
--EXPECTF--
bool(true)
Interface [ <internal:streams2> interface Stream\Context ] {

  - Constants [0] {
  }

  - Static properties [0] {
  }

  - Static methods [0] {
  }

  - Properties [0] {
  }

  - Methods [5] {
    Method [ <internal:streams2> abstract public method getOption ] {

      - Parameters [2] {
        Parameter #0 [ <required> string $scheme ]
        Parameter #1 [ <required> string $option ]
      }
    }

    Method [ <internal:streams2> abstract public method getSchemeOptions ] {

      - Parameters [1] {
        Parameter #0 [ <required> string $scheme ]
      }
      - Return [ array ]
    }

    Method [ <internal:streams2> abstract public method getAllOptions ] {

      - Parameters [0] {
      }
      - Return [ array ]
    }

    Method [ <internal:streams2> abstract public method getParam ] {

      - Parameters [1] {
        Parameter #0 [ <required> string $param ]
      }
    }

    Method [ <internal:streams2> abstract public method getAllParams ] {

      - Parameters [0] {
      }
      - Return [ array ]
    }
  }
}
