#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�C�۸�");

 set("long",@LONG
�A�o�{�@���W����H��ӳ��O�n�e���ѱ��@����������
����, �ѱ��b�Q�U�j�s���۷�h���H�{, �]��, �ѱ�������
�̬۷��h.
LONG
    );
 set("exits",([	"north":__DIR__"ten39",
		"south":__DIR__"ten37",
    ]));
 set("objects", ([__DIR__"npc/prayer" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}