package org.ahmedfahim;

import lombok.extern.slf4j.Slf4j;
import org.ahmedfahim.data.structure.PrefixTree;
import org.ahmedfahim.data.structure.impl.PrefixTreeImpl;

import java.util.Arrays;
import java.util.List;

@Slf4j
public class PrefixTreeApp {
    static void demonstrateImplementation() {
        List<String> putStrings = Arrays.asList("Fahim", "Goku", "Vegeta", "Beerus", "fahim");

        PrefixTree prefixTree = new PrefixTreeImpl();
        for(String name : putStrings) {
            prefixTree.insert(name);
        }

        log.info("prefixTree = {}", prefixTree);
    }

	public static void main(String[] args) {
        demonstrateImplementation();
	}
}
