#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�w�L"NOR);

 set("long",@LONG
�A�o�{�w�L��B���O����, �ϧA�����ݨ�e����ԣ�F��, ��
�O�n�����٬O�S���x����, �A���T�P�ĳo�˪��a�z�{�H�����_,
�O�H�Ĭ��[��.
LONG
    );
 set("exits",([ "west":__DIR__"med15",
		"north":__DIR__"med13",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}