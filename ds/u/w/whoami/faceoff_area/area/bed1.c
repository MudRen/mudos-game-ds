#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�q�Q"NOR);
set("long",@LONG
�A�o�{�o�����M��F���֪��H, ���o�N�~�F���b�M�w�R, �o
�̤֤F�ȴ̪�����, ���ӥN�����o�O�@�Ѧw�R�ԩM�����n��^
���A���T�Q�b�o�̥𮧤@�U.
LONG
    );
 set("exits",([ "east":__DIR__"bed2",
                "south":__DIR__"walk7",
 ]));
 set("objects", ([__DIR__"npc/prayer" : 2,
             __DIR__"npc/bird_waiter":1,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
