#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�_�ٮp");

 set("long",@LONG
�A�O�ɤF�d���U�W, �ש��W�F�_�ٮp���g�a, �u�O���A�P
�ʸU��, �q�o�̩��F�h�O�^������p���s��, �A����_��e�i�h
�|����V.
LONG
    );
 set("exits",([	"west":__DIR__"ten11",
		"eastdown":__DIR__"ten9",
		"north":__DIR__"ten13",
    ]));
 set("objects", ([__DIR__"npc/eagle" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}