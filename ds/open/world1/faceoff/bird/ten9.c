#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s��");

 set("long",@LONG
�q�o�̦A�����@�ǧY�i��Q�U�j�s���̰����_�ٮp, ��
�F�h�O�����p�����p, �A�o�{�o���s�������j�{�׹�b���U��
�z�D, �ϧA�P��o�B����.
LONG
    );
 set("exits",([ "westup":__DIR__"ten10",
		"eastdown":__DIR__"ten2",
    ]));
 set("objects", ([__DIR__"npc/wood_cutter" : 1,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}