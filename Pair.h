#pragma once

template <class Key, class Value>
class Pair {
	Key* _keys;
	Value* _values;
	int _capacity;
	int _count{ 0 };

public:
	Pair(int capacity) {
		_capacity = capacity;
		_keys = new Key[_capacity];
		_values = new Value[_capacity];
	}

	~Pair() {
		delete[] _keys;
		delete[] _values;
	}

	void add(const Key& key, const Value& value) {
		if (contains_key(key)) return;

		_keys[_count] = key;
		_values[_count] = value;
		_count++;
	}

	bool contains_key(const Key& key) {
		for (int i = 0; i < _count; i++)
			if (_keys[i] == key)
				return true;

		return false;
	}

	Value* get_value(const Key& key) {
		for (int i = 0; i < _count; i++)
			if (_keys[i] == key)
				return &_values[i];

		return nullptr;
	}

	Value& operator[] (const Key& key) {
		auto* value = get_value(key);
		if (value != nullptr)
			return *value;

		exit(1);
	}
private:
};
