#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>

using namespace sf;
using namespace std;

class Animator
{
public:
	struct Animation
	{
		string m_Name;
		string m_TextureName;
		vector<IntRect> m_Frames;
		Time m_Duration;
		bool m_Looping;

		Animation(string const& name, string const& textureName,
			Time const& duration, bool looping)
			: m_Name(name), m_TextureName(textureName),
			m_Duration(duration), m_Looping(looping)
		{}

		// Adds frames horizontally
		void AddFrames(Vector2i const& startFrom,
			Vector2i const& frameSize, unsigned int frames)
		{
			Vector2i current = startFrom;
			for (unsigned int i = 0; i < frames; i++)
			{
				// Add current frame from position and frame size
				m_Frames.push_back(IntRect(current.x, current.y, frameSize.x, frameSize.y));
				// Advance current frame horizontally
				current.x += frameSize.x;
			}
		}
	};

	Animator(Sprite& sprite);

	Animator::Animation& CreateAnimation(string const& name,
		string const& textureName, Time const& duration, bool loop = false);

	void Update(Time const& dt);

	// Returns if the switch was successful
	bool SwitchAnimation(string const& name);

	string GetCurrentAnimationName() const;
private:
	// Returns the animation with the passed name
	// Returns nullptr if no such animation is found
	Animator::Animation* FindAnimation(string const& name);

	void SwitchAnimation(Animator::Animation* animation);

	// Reference to the sprite
	Sprite& m_Sprite;
	Time m_CurrentTime;
	list<Animator::Animation> m_Animations;
	Animator::Animation* m_CurrentAnimation;
};