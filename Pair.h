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
		if (_count >= _capacity) resize();

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

	int get_count() {
		return _count;
	}

	Value* get_value(const Key& key) {
		for (int i = 0; i < _count; i++)
			if (_keys[i] == key)
				return &_values[i];

		return nullptr;
	}

	Key* begin() {
		return _keys;
	}

	Key* end() {
		return _keys + _count;
	}

	Value& operator[] (const Key& key) {
		auto* value = get_value(key);
		if (value != nullptr)
			return *value;

		exit(1);
	}

private:
	void resize() {
		_capacity = _count + 4;
		auto* tmp_keys = new Key[_capacity];
		auto* tmp_values = new Value[_capacity];

		auto end = _count - 1;
		for (int i = 0; i < end; i++) {
			tmp_keys[i] = _keys[i];
			tmp_values[i] = _values[i];
		}

		delete[] _keys;
		delete[] _values;

		_keys = tmp_keys;
		_values = tmp_values;
	}

	bool index_in_range(int index) {
		return index >= 0 && index < _count;
	}
};
