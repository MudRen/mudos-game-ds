#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ϸz�D�J�f");

 set("long",@LONG
�p�G�q�o�̦A���_��N�|�i�J�ϸz�D����, �ǻ��ϸz�D���D
���۷��j, �N��O���۷�Ȧ�g�窺�ȤH, �]����������J�o
��, �ݨӧA�ӬO���n�^������p�a.
LONG
    );
 set("exits",([	"northeast":__DIR__"ten22",
		"south":__DIR__"ten20",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}