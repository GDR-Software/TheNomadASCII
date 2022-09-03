#ifndef _SOUNDS_H_
#define _SOUNDS_H_

#ifdef _WIN32
	#pragma once
	class Sounds
	{
	public:
		void mfx(const std::string filename)
		{
		
		}
		void sfx(const std::string filename)
		{
		
		}
	};
#else
// any other OS since I don't have a damned clue how to write sound drivers and shit
	class Sounds
	{
	public:
		void playMusic(const std::string filename)
		{
			sf::Music music;
			if (!music.openFromFile("../Sounds/Music/" + filename + ".flac")) // all music files will be .flac
				return;

			music.play();
		}
		void playSound(const std::string& filename)
		{
			sf::SoundBuffer buffer;
			if (!buffer.loadFromFile("../Sounds/Effects/" + filename + ".wav"))
				return;

			sf::Sound sound(buffer);
			sound.play();
		}
	};
#endif

#endif