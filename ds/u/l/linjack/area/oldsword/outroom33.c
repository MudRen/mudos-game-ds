#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ζH��");
 set("long",@LONG
�A�Ө�F�@�Ӭ����G�Q�ت��j�����۪O�W, �W�����ۤ@��
�j�����|��Υۮ�, �����T��, ���F�d��. �A���������D�o��
�����򰵥�, �O������? �٬O....
LONG
    );
 set("exits",([ "northwest":__DIR__"outroom31",
                "southwest":__DIR__"outroom34",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
