#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�|");

 set("long",@LONG
�q�o�̩��訫�|��b�Ķ�̷åB�t����L, ���̰�Բ����
�O�@�ǳߦn���㪺�Ӫ�, ���L, ���i�h�O�@��۷��������ƴN
�O�F...
LONG
    );
 set("exits",([ "west":__DIR__"med18",
		"east":__DIR__"med16",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}