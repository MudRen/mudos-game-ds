#include <ansi.h>
#include <room.h> 

inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");

 set("long",@LONG
�A�{�b�Ө�@�B���L�ߪ��a��, �@�}�}���������Ө�, ��
�W���@�諸�ͥ��b���T�T���s��, �n���w��A�Ө�o��, ������
�F��M�_����}, �Ať�줣���B���H����n���C
LONG
 );
 
 set("exits",(["north":__DIR__"en5",
               "east":__DIR__"en4",
               "southwest":__DIR__"en2",
     ]));
        set("objects",([__DIR__"npc/chan" : 1+random(5),
               ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
 setup();
}

