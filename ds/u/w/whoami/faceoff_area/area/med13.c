#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�w�L"NOR);

 set("long",@LONG
�o�̬O�w�L���J�f, �A���Y�W��, �o�{�A�M�ѪŤ������@�D
�H�H������, �A���M�Q�_�a�z���@�إs�H�ު��W��, �b���̯S�O
�H�N, �Q�Ӱw�L�N�O�o�˪��a��a?
LONG
    );
 set("exits",([ "south":__DIR__"med14",
		"west":__DIR__"med16",
		"east":__DIR__"med12",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}