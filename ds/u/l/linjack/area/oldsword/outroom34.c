#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ѶH��");
 set("long",@LONG
�A�Ө�F�@�Ӭ����G�Q�ت��j�T���۪O�W, �W�����ۤ@��
�j���������Υۮ�, �����T��, ���F�d��. �A���������D�o��
�����򰵥�, �O������? �٬O....
LONG
    );
 set("exits",([ "northwest":__DIR__"outroom32",
                "northeast":__DIR__"outroom33",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
