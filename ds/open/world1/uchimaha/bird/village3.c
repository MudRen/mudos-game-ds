#include <room.h>
inherit ROOM;
void create()
{
 set("short","�y����");
 set("long",@LONG
�A�{�b�Ө�F�y�������J�f�B, �A���Y���W�@��,
���@�Ӱ��E���ت����������b�A�����W��, �����W����
���@�ǳ³�, ���F�K�O�y�������s��.
LONG
    );
 
 set("exits",(["west":__DIR__"village2",
               "east":__DIR__"village4",
           ]));
 set("objects",([__DIR__"npc/villager" : 3,
     ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
