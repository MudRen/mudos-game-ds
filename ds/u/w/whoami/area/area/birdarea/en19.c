#include <room.h> 
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");

 set("long",@LONG 
�A�{�b�Ө�F�_�A�L���`�B, �o����S������F��, �u����
�Ǫ����O, �M���W���X�ڤp��, �e��ݰ_�Ӫh��ܭ�, �i��֨�
�h�A�a�a�F, �o�����@�����F�詵���U�h�C
LONG
    );
 
 set("exits",(["west":__DIR__"en18",
               "east":__DIR__"en20",
             ]));
 set("objects",([__DIR__"npc/q1" : 1,
     ]));
 set("no_clean_up", 0);
 set("outdoors","forest");
 setup();
 replace_program(ROOM);
}           

