#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ū�"NOR);

 set("long",@LONG
�A�o�{��Ө��Ӥj�j�������W����O�@�Ӥj�j���|, �̭�
�ˤF�۷�h���u��, �|�P��H�𸭵���, �ΨӴ��ѪF�_�a�ϩ�
�S��������.
LONG
    );
 set("exits",([ "south":__DIR__"med10",
		"west":__DIR__"med8",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}