#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","��l");

 set("long",@LONG
�o�̤��M�O��l�����A�Ѱ�, �A�o�{�|�P���ǹA���x���b�|
�B����, �ݦ��L�i�å��l�b�|�P����, �����o���񪺱j�s�դO�D
�`�j�j.
LONG
    );
 set("exits",([	"east":__DIR__"ten27",
		"north":__DIR__"ten31",
    ]));
 set("objects", ([__DIR__"npc/soldier" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}