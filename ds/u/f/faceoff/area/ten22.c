#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ϸz�D");

 set("long",@LONG
�q�o�̤w�g�i�J�F�ϸz�D, �ǻ��o�̱j�s�۷��h, ���O�i
�J���B���s���L�Ȥ]�۷��h, ���������N�O�䤤���@��˳˳��
, �ݨӧA���ӭn�p�ߤ@��.
LONG
    );
 set("exits",([	"north":__DIR__"ten23",
		"southwest":__DIR__"ten21",
    ]));
 set("objects", ([__DIR__"npc/chiu" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}