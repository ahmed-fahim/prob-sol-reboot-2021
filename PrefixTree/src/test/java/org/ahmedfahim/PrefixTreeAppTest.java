package org.ahmedfahim;

import org.ahmedfahim.data.structure.PrefixTree;
import org.ahmedfahim.data.structure.impl.PrefixTreeImpl;
import org.junit.Test;

import java.util.Arrays;
import java.util.List;
import java.util.Set;

/**
 * Unit test for simple PrefixTreeApp.
 */
public class PrefixTreeAppTest {
	@Test
	public void testCorrectNess() {
		Set<String> putStrings = Set.copyOf(Arrays.asList(
				"Fahim", "Goku", "Vegeta", "Beerus", "fahim"));

		PrefixTree prefixTree = new PrefixTreeImpl();
		for (String name : putStrings) {
			prefixTree.insert(name);
		}

		List<String> testStrings = Arrays.asList("Fahim", "goku", "vegeta", "beerus");

		for (String testStr : testStrings) {
			boolean assertExpectation = true;
			if (!putStrings.contains(testStr)) {
				assertExpectation = false;
			}
			assert (prefixTree.contains(testStr) == assertExpectation);
		}
	}
}
