#include <room.h>
inherit ROOM;
void create()
{
 set("short","�k�H��");
 set("long",@LONG
�A�Ө�F�@�Ӭ����G�Q�ت��j��Υ۪O�W, �W�����ۤ@��
�j�����T�����ۮ�, �����T��, ���F�d��. �A���������D�o��
�����򰵥�, �O������? �٬O....
LONG
    );
 set("exits",([ "northeast":__DIR__"outroom31",
                "southeast":__DIR__"outroom34",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
