#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","��l");

 set("long",@LONG
�A�ݨ�o�̦��@�ӶťD���b�v�a�v�᪺�����Ű�, ���O�o��
�A�H�ұo�n�k�f������, �󤣥λ��n�h�ٶŤF, �A���P���ߤ��T
�ϧA�Q�n���U�L��...
LONG
    );
 set("exits",([	"south":__DIR__"ten28",
		"west":__DIR__"ten30",
    ]));
 set("objects", ([__DIR__"npc/rich" : 1,
                  __DIR__"npc/guard":2,
		  __DIR__"npc/farmer3":1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}