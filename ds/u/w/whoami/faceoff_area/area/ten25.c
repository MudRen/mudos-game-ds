#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ϸz�D");

 set("long",@LONG
�ש�i�H�ݨ�ϸz�D�����ݤF, �ϸz�D�����ݴN�b�A���F�_
�褣���B, �A�o�{�o�̩_�ݦ������@�Ǹq���x�b��u, ���@�b��
�l���ͬ����A��.....
LONG
    );
 set("exits",([	"northeast":__DIR__"ten26",
		"southwest":__DIR__"ten24",
    ]));
 set("objects", ([__DIR__"npc/wind_ranger" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}