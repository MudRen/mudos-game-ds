#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�w�L"NOR);
 set("long",@LONG
�o�̦A���訫�N�X�F�H�ޤF, �]�N�O����ŧY�N�^��`��, 
���O�A�٬O�i�H�b�o�̧��A�ҭn���ħ�.
LONG
    );
 set("exits",([ "west":__DIR__"med17",
		"east":__DIR__"med13",
		"south":__DIR__"med15",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}