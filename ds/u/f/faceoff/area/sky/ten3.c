#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�_�ٮp"NOR);
 set("long",@LONG
�A�q�o�̥i�H�ݨ��A���F�_�観�@�y�C�⪺�J���A����
�̵M�p�@��Q�b����V�A���y�A�Ʀܳz�L�A���窫��E�ۧA
������A�A�}�l�h�áA�o�˪��ѵM���ҡA���G�O���w��A��
�o�̨�....
LONG
    );
 set("exits",([   "northeast":__DIR__"ten5",
               "southwest":__DIR__"ten2",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

