#include <room.h>
inherit ROOM;
void create()
{
 set("short","�I�v�j��");
 set("long",@LONG
�A�Ө�F�y�������}�@�����I�����e, �A���e�O�@
�����j�������j��, ����٦��@��i���Z�����۷�l,
�b�A�}�䦳�@�ƤQ�����۶�, �۶��s���ۤj���E
LONG
    );
 
 set("exits",(["south":__DIR__"village15",
               "enter":__DIR__"rich2",
              ]));
 set("objects",([__DIR__"npc/dog" : 1,
               ]));
 setup();
create_door("enter","�����j��","out",DOOR_OPENED,"nokey");
}        
