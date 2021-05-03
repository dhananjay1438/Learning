class metaBase(type):
    def __new__(cls, classname, bases, data):
        if not 'bar' in data:
            raise TypeError("bad class")
        return super().__new__(cls, classname, bases, data)


class Base(metaclass=metaBase):
    def bar(self):
        print("Base bar")

    def foo(self):
        print("foo")


class Derived(Base):
    def some(self):
        print("some")
