#include <room.h>
inherit ROOM;
void create()
{
 set("short","���H��");
 set("long",@LONG
�A�Ө�F�@�Ӭ����G�Q�ت��j��Υ۪O�W, �W�����ۤ@��
�j��������ۮ�, �����T��, ���F�d��. �A���������D�o��
�����򰵥�, �O������? �٬O....
LONG
    );
 set("exits",([ "east":__DIR__"outroom30",
                "north":__DIR__"outroom29",
                "southwest":__DIR__"outroom32",
                "southeast":__DIR__"outroom33",
                "south":__DIR__"secret1_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
