#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�_�ٮp");

 set("long",@LONG
�o�̬O�_�ٮp���F��, �u���A�������G���@�Ӥp�p���T
��, �����D�O�֦�b����? ���_�h�|��_�ٮp���_��, �q����
�A������N�O���V�F.
LONG
    );
 set("exits",([	"west":__DIR__"ten12",
		"east":__DIR__"ten10",
		"north":__DIR__"ten14",
    ]));
 set("objects", ([__DIR__"npc/eagle" : 3,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}