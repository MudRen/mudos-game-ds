#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�|");

 set("long",@LONG
�o�O�@���p�p���p�|, ���_���|�^��ѱ��Ķ骺�J�f, �ө�
�F���N�|��·t����L�F.
LONG
    );
 set("exits",([ "north":__DIR__"med1",
		"east":__DIR__"med21",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}