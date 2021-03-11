# B-CPP-501-PAR-5-1-rtype-gaetan.depin

## Component
[Documentation](./doc/component.md)


## PROTOCOL

#### 1. client connect
    -> CONNECT_ERR  ==> check your internet connection and retry. Server may be unavailable
    -> CONNECT_OK   ==> #### 2 

#### 2.1. join room
    -> ROOM_UNAVAILABLE ==> try to connect to another room
    -> ROOM_JOIN_ERR    ==> server internal error. Try again or connect to another room
    -> ROOM_JOIN_OK     ==> #### 3
#### 2.2. create room
    -> ROOM_CREATE_ERR  ==> try again or join existing room
    -> ROOM_CREATE_OK   ==> #### 3 or #### 4

#### 3. update your 'ready' status
    -> READY_STATUS_ERR ==> server internal error, try again
    -> READY_STATUS_OK  ==> if game owner #### 5.1 else #### 5.2
    -> ROOM_DESTROYED   ==> #### 2

#### 4. destroy room
    -> DESTROY_ROOM_ERR ==> server internal error, try again
    -> DESTROY_ROOM_OK  ==> #### 2

#### 5.1 launch game
    -> PLAYERS_NOT_READY ==> wait for all players to be ready and relaunch
    -> GAME_LAUNCH_ERR   ==> server internal error, try again
    -> GAME_LAUNCH_OK    ==> #### 6
#### 5.2 wait beginning of the game
    -> GAME_LAUNCH_OK ==> #### 6
    -> ROOM_DESTROYED ==> #### 2

#### 6 Game Running
##### 6.1 shoot
    -> PLAYER_SHOOT_OK  ==>
    -> PLAYER_SHOOT_ERR ==>
##### 6.2 move
    -> PLAYER_MOVE_ERR ==>
    -> PLAYER_MOVE_OK  ==>
##### 6.3 take damage
    -> PLAYER_DAMAGE_ERR ==>
    -> PLAYER_DAMAGE_OK  ==>
##### 6.4 add score
    -> PLAYER_SCORE_ERR ==>
    -> PLAYER_SCORE_OK  ==>
##### 6.5 touch enemy
    -> PLAYER_TOUCH_ERR ==>
    -> PLAYER_TOUCH_OK  ==>
##### 6.6 kill enemy
    -> PLAYER_KILL_ERR ==>
    -> PLAYER_KILL_OK  ==>
