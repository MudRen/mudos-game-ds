#include <room.h>
inherit ROOM;
void create()
{
 set("short","��W�W");
 set("long",@LONG
�o�ӯ�W���I���`���w�R, �s���n���S��, �u��ť��
�ӷL���y���n, �]�S������ʪ��b�o��X�S, �_����Z
��, �O���շt���p��, �F�䦳�Ӥp�۫�.
LONG
    );
 set("exits",([ "west":__DIR__"outroom8",
                "east":__DIR__"s_room",
               "south":__DIR__"outroom11",
               "north":__DIR__"outroom12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}