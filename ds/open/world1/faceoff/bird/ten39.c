#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�C�۸�");

 set("long",@LONG
�֨�C�۸������Y�F, �A�o�{��Ӥѱ�������, �����@���b
�ѱ��M�Ĥ@���Q�ѭĵ�, �@�譱�]�O�]���ѱ��M�Ĥ@���������
�C, �@�譱�j���]�O�]������a....
LONG
    );
 set("exits",([	"north":__DIR__"ten40",
		"south":__DIR__"ten38",
    ]));
 set("objects", ([__DIR__"npc/prayer" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}