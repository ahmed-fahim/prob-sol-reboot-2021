package org.ahmedfahim.data.structure.impl;

import org.ahmedfahim.data.structure.PrefixTree;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class PrefixTreeImpl implements PrefixTree {
	private final char id;
	private final Map<Character, PrefixTreeImpl> subTreeMap;
	private boolean word;

	public PrefixTreeImpl() {
		this((char) 0);
	}

	private PrefixTreeImpl(char id) {
		this.id = id;
		this.word = false;
		this.subTreeMap = new HashMap<>();
	}

	private void insert(String s, int index) {
		if (s.length() == index) {
			this.word = true;
			return;
		}
		char key = s.charAt(index);
		PrefixTreeImpl childTree = this.subTreeMap.containsKey(key) ?
				this.subTreeMap.get(key) : new PrefixTreeImpl(key);
		childTree.insert(s, index + 1);
		this.subTreeMap.put(key, childTree);
	}

	@Override
	public void insert(String s) {
		this.insert(s, 0);
	}

	private boolean contains(String s, int index) {
		if (index == s.length()) {
			return this.word;
		}
		char key = s.charAt(index);
		return this.subTreeMap.containsKey(key) && this.subTreeMap.get(key).contains(s, index + 1);
	}

	@Override
	public boolean contains(String s) {
		return this.contains(s, 0);
	}

	private ArrayList<String> listAllStrings(String prefixString) {
		ArrayList<String> localCollection = new ArrayList<>();
		prefixString = String.format("%s%c", prefixString, this.id);

		if (this.word) {
			localCollection.add(prefixString);
		}

		for (Map.Entry<Character, PrefixTreeImpl> pair : this.subTreeMap.entrySet()) {
			localCollection.addAll(pair.getValue().listAllStrings(prefixString));
		}
		return localCollection;
	}

	private List<String> listAllStrings() {
		ArrayList<String> finalCollection = new ArrayList<>();
		for (Map.Entry<Character, PrefixTreeImpl> pair : this.subTreeMap.entrySet()) {
			finalCollection.addAll(pair.getValue().listAllStrings(""));
		}
		return finalCollection;
	}

	@Override
	public String toString() {
		StringBuilder stringBuilder = new StringBuilder();
		List<String> collection = listAllStrings();
		for (String token : collection) {
			stringBuilder.append(String.format("\t%s%n", token));
		}
		return String.format("{%n%s}", stringBuilder.toString());
	}
}
