package br.ufscar.lince.streaming;

abstract class JWrapper {
	static {
		System.loadLibrary("streamingjava");
	}
	
	protected long pointer;
}
