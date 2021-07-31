package org.ahmedfahim;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

class PrefixTree {
	private final Map<Character, PrefixTree> subTreeMap;
	int value;
	int descendentSum;

	public PrefixTree() {
		this((char) 0);
	}

	private PrefixTree(char id) {
		this.subTreeMap = new HashMap<>();
		this.value = 0;
		this.descendentSum = 0;
	}

	private int deltaAfterInsert(String s, int index, int value) {
		if (s.length() == index) {
			int delta = value - this.value;
			this.value = value;
			return delta;
		}
		char key = s.charAt(index);
		PrefixTree childTree = this.subTreeMap.containsKey(key) ?
				this.subTreeMap.get(key) : new PrefixTree(key);
		int delta = childTree.deltaAfterInsert(s, index + 1, value);
		this.descendentSum += delta;
		this.subTreeMap.put(key, childTree);
		return delta;
	}

	public void insert(String s, int value) {
		this.deltaAfterInsert(s, 0, value);
	}

	private PrefixTree get(String s, int index) {
		if (index == s.length()) {
			return this;
		}
		char key = s.charAt(index);
		return this.subTreeMap.containsKey(key) ?
				this.subTreeMap.get(key).get(s, index + 1) : null;
	}

	public PrefixTree get(String s) {
		return this.get(s, 0);
	}

	public int getPrefixSum(String s) {
		PrefixTree prefixTree = this.get(s);
		return Objects.nonNull(prefixTree) ? (prefixTree.value + prefixTree.descendentSum) : 0;
	}
}

class MapSum {
	private final PrefixTree prefixTree;

	/**
	 * Initialize your data structure here.
	 */
	public MapSum() {
		this.prefixTree = new PrefixTree();
	}

	public void insert(String key, int val) {
		this.prefixTree.insert(key, val);
	}

	public int sum(String prefix) {
		return this.prefixTree.getPrefixSum(prefix);
	}
}


public class App {
	public static void main(String[] args) {
		MapSum mapSum = new MapSum();
		mapSum.insert("AB", 5);
		mapSum.insert("ABC", 3);
		mapSum.insert("A", 1);
		System.out.println(mapSum.sum("BC"));
	}
}
