--TEST--
Test registering/unregistering a wrapper
--FILE--
<?php
$scheme = 'foo';
var_dump(\Stream\Wrapper\register(
    $scheme,
    function () {
        return new class ('foo://bar', 'mode') implements \Stream {
            public function __construct(string $uri, string $mode, ?Stream\Context $ctx = null)
            {
            }

            public function getName(): string
            {
                return 'bar';
            }

            public function getUri(): string
            {
                return 'foo://bar';
            }

            public function isOpen(): bool
            {
                return true;
            }
            public function read(int $maxbytes = 0): string
            {
                return '';
            }
            public function write(string $data): int
            {
                return strlen($data);
            }
            public function flush(): bool
            {
                return true;
            }
            public function close(): void
            {
            }

            public function seek(int $pos, int $whence = Stream::SEEK_SET): bool
            {
                return true;
            }
            public function isSeekable(): bool
            {
                return true;
            }
            public function stat(): Stream\StatBuf
            {
                return new class implements \Stream\StatBuf {
                };
            }
            public function setOption(int $option, $value): bool
            {
                return true;
            }
            public function getStream(): Stream
            {
                return $this;
            }
        };
    }
));

// @todo register, then check exists, then unregister, then check exists etc.
echo \Stream\Wrapper\exists($scheme) . "\n";
echo \Stream\Wrapper\getWrapper($scheme) . "\n";
echo \Stream\Wrapper\unregister($scheme);
--EXPECT--
bool(true)
Stream\Wrapper\exists() not implemented yet...
Stream\Wrapper\getWrapper() not implemented yet...
Stream\Wrapper\unregister() not implemented yet...
