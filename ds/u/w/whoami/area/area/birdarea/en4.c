#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");
 set("long",@LONG
�A�Ө�F�F�_�A�L������, �o�̦��\�h������, ���b�V�O
�������, �L�̪����@�w�@�w���y�U, �A���_���N�O�L�H����
�L�`�B�F�C 
LONG);
 
 set("exits",(["north":__DIR__"en6",
               "west":__DIR__"en3",
             ]));
 set("objects",([__DIR__"npc/cutter" : 3+random(5),
               ]));
 
 set("no_clean_up", 0);
 set("outdoors","forest");
 setup();
}

