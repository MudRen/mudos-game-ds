#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�T��");

 set("long",@LONG
�A�ݨ�o�̦��@��ѤH���b���n�Į�, �����D������x��
, �A���Y�ݨ��F�@�ӫC�ɻs��������, ���D�o�ӦѤH��ѱ���
���������s?
LONG
    );
 set("exits",([	"east":__DIR__"ten11",
    ]));
 set("objects", ([__DIR__"npc/old_man" : 1,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}