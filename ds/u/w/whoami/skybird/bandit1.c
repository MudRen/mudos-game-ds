#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void create()
{
 set("short","���");
 set("long",@LONG 
�A�����x�l�i�F���, �u���|�P���u�ì۷��Y�K, ���W�٦�
�@�ǽb�եi�H�V�~�g�b, ���n���x�L�ڥ����޳o��, �N��n��, 
�n�i��i�h�]����.
LONG
    );
 set("exits",([ "northwest":__DIR__"bandit3",
                "southeast":__DIR__"bandit2",
                "northeast":__DIR__"bandit4",
                "out":__DIR__"ten6",
    ])); 
 set("objects", ([__DIR__"npc/archer" : 1+random(4),
    ]));

 set("no_clean_up",0);
 set("light",0);
 setup();
 create_door("out","�p���K��","enter",DOOR_LOCKED,"nokey");
}

