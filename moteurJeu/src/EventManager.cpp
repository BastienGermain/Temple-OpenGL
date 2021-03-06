#include "moteurJeu/EventManager.hpp"

EventManager::EventManager() 
    : _mouseButtonDown(false), _lastClickPosition(glm::vec2(0)), _mouseMotionDelta(glm::vec2(0)), _camTrack(true), _changeCam(true), _tempLock(true), _camLocked(false)
{
}

EventManager::~EventManager()
{
}

void EventManager::handleEvent(SDL_Event *event, Player &player, TrackballCamera &track, FreeflyCamera &fly)
{
    switch (event->type)
    {
        case SDL_QUIT:
            onExit();
            break;

        case SDL_KEYDOWN:
            switch(event->key.keysym.sym)
            {
            	// JUMP
                case SDLK_z:
                    if (!player._jumping && !player._landing)
                        player._jumping = true;
                    break;
                    
                 case SDLK_UP:
                    if (!player._jumping && !player._landing)
                        player._jumping = true;
                    break;

                // MOVE LEFT
                case SDLK_q:
                    player.goLeft(fly);
                    player._turningLeft = true;
                    break;

                case SDLK_LEFT:
                    player.goLeft(fly);
                    player._turningLeft = true;
                    break;

                // MOVE RIGHT
                case SDLK_d:
                    player.goRight(fly);
                    player._turningRight = true;
                    break;

                case SDLK_RIGHT:
                    player.goRight(fly);
                    player._turningRight = true;
                    break;

                // ZOOM
                case SDLK_a:
                    if (_camTrack && !_camLocked)
                    {
                        track.moveFront(track.smoothness());
                    }
                    break;

                case SDLK_e: 
                    if(_camTrack && !_camLocked)
                    {
                        track.moveFront(-track.smoothness());
                    }
                    break;

                case SDLK_l:
                    if (_tempLock)
                    {
                        _camLocked = !_camLocked;
                        _tempLock = false;
                    }                    
                    break;

                case SDLK_c:
                    if (_changeCam)
                    {
                        _camTrack = !_camTrack;
                        _changeCam = false;
                    }                    
                    break;

                default:
                    break;
           }
           break;

        case SDL_KEYUP:
            _changeCam = true;
            _tempLock = true;
            player.goCenter(fly);
            player._turningRight = false;
            player._turningLeft = false;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (event->button.button == SDL_BUTTON_LEFT) 
            {
                _mouseButtonDown = true;
                _lastClickPosition = glm::vec2(event->button.x, event->button.y);
            }
            break;

    	case SDL_MOUSEBUTTONUP:
    		if (event->button.button == SDL_BUTTON_LEFT) 
    		{
	    		_mouseButtonDown = false;
	    		_mouseMotionDelta = glm::vec2(0);
    		}
    		break;

    	case SDL_MOUSEMOTION:
            if (!_camLocked)
            {
        		if (_mouseButtonDown) 
        		{
        			_mouseMotionDelta.x = event->button.x - _lastClickPosition.x;
        			_mouseMotionDelta.y = event->button.y - _lastClickPosition.y;
                    if (_camTrack)
                    {
                        track.rotateLeft(track.smoothness() * _mouseMotionDelta.x);
                        track.rotateUp(track.smoothness() * _mouseMotionDelta.y);
                    }
                    else
                    {
                        fly.rotateLeft(fly.smoothness() * _mouseMotionDelta.x);
                        fly.rotateUp(fly.smoothness() * _mouseMotionDelta.y);
                    }
        		}
            }
    		break;
    }

    if (player._jumping)
        player.jump(fly);
    if (player._landing)
        player.land(fly);
}

void EventManager::onExit() {
	exit(0);
}