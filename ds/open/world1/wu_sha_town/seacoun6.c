#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�L����");
set("long",@LONG
�o�̬O�L�����¥���, �A�ݨ�A���F�話�����ۦѰO��
�Q���۵P, �Ӧ�誺�����h�O�溮����, ���_�h�|����F�q, 
�ѰO��Q�O�b�L����}���H�ӲĤ@�a��Q, �]��ܦ��o....
LONG
    );
 set("exits",([ "north":__DIR__"seacoun7",
		"south":__DIR__"seacoun5",
		"west":__DIR__"seacoun18",
		"east":__DIR__"seacoun19",
]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
}

int valid_leave(object me, string dir)
{
       if( dir=="south" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}