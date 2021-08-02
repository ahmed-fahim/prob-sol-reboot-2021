package org.ahmedfahim;


import java.util.Collections;
import java.util.List;
import java.util.TreeMap;
import java.util.stream.Collectors;

//class Solution {
//	private static final Long MOD = 1000000007L;
//
//	private long sequentialSum(long start, long end) {
//		long n = (end - start) + 1;
//		long d = 1;
//		long sum = (2 % MOD * start % MOD) % MOD;
//		sum = sum + (n-1) % MOD;
//		sum = (sum%MOD * n%MOD);
//		return sum/2;
//	}
//
//
//	public int maxProfit(int[] inventory, int orders) {
//		TreeMap<Integer, Integer> distinctElementCounter = new TreeMap<>();
//		for (int element : inventory) {
//			distinctElementCounter.put(element, distinctElementCounter.getOrDefault(element, 0) + 1);
//		}
//
//		List<Integer> distinctElementList = distinctElementCounter
//				.keySet()
//				.stream()
//				.collect(Collectors.toList());
//
//		Collections.reverse(distinctElementList);
//
//		long cost = 0;
//		int seekElement = distinctElementList.size()-1;
//		while (orders > 0 && seekElement >= 0) {
//			int elementCount =
//			long delta = Math.min(orders,
//					distinctElementCounter.get(distinctElementList.get(seekElement)));
//		}
//	}
//}

public class App {
	private static final Long MOD = 1000000007L;
	public static void main(String[] args) {
		long start = 2L;
		long end = 5L;
		long n = (end - start) + 1;
		long d = 1;
		long sum = (2 % MOD * start % MOD) % MOD;
		sum = sum + (n-1) % MOD;
		sum = (sum%MOD * n%MOD);
		System.out.println(sum/2);


	}
}
