#include <room.h>
inherit ROOM;
void create()
{
 set("short","�e��");
 set("long",@LONG
�o��O�@���e��, �J�Ӭݬݪ���, �A�N�|ı�o����n����
�����G������@��. ���L�ѩ�Q�����t�����Y, �A�L�k����|
�P���|�����p.
LONG
    );
 set("exits",([ "west":__DIR__"secret2_8",
                "southwest":__DIR__"secret2_15",
                "south":__DIR__"secret2_13",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
