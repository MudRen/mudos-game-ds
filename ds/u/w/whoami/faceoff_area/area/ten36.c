#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�C�۸�");

 set("long",@LONG
�A�����}����b�q���ѱ��M�Ĥ@�����C�۸��W, �A�o�{�@
���W�èS�������H, �ݨӤѱ��M�Ĥ@���ä����w�Ӧh���H, 
����o�L���w���w��A....
LONG
    );
 set("exits",([	"north":__DIR__"ten37",
		"south":__DIR__"ten35",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}