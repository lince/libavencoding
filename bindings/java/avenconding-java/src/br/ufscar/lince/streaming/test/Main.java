package br.ufscar.lince.streaming.test;

import br.ufscar.lince.streaming.*;

public class Main {

	public static void main(String[] args) {
		AVSource screen = new X11Terminal(800, 800, 25);
		AVEncoder video = new AVEncoder(screen);
		video.setVideoCodec(VideoCodec.H264);
		video.setVideoPreset("ultrafast");
		video.setPropertyValue("crf", "22");
		
		AVSource file = new AVInputFile("home/caioviel/saida.mp4", "mp4");
		AVEncoder sound = new AVEncoder(file);
		sound.enableCopyAudio();
		
		//AVSource videoDemo = new AVInputFile("/home/caioviel/videomenna.avi", "avi");
		//AVEncoder video2 = new AVEncoder(videoDemo);
		//video2.enableCopyAudio();
		Streaming streamer = new UDPMpegTS("127.0.0.1", 5004);
		//Streaming streamer = new RTPStream("127.0.0.1", 5004);
		System.out.println("Estamos aqui!");
		//streamer.addStream(video);
		streamer.addStream(sound);
		streamer.start();
		streamer.waitFinishing();
	}
}
