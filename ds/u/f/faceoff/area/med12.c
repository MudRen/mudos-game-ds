#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�|");

 set("long",@LONG
�A�w�g�i�H�q�o��ݨ�b�F�褣���B���w�L�F, �u���F��
����½�], �ݨӴN�O�ܧN���ˤl, ���Ṋ̀��شӪ����O�ݴH��
��....
LONG
    );
 set("exits",([ "north":__DIR__"med11",
		"west":__DIR__"med13",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}