#include <room.h>
inherit ROOM;
void create()
{
 set("short","��^�j�Y");
 set("long",@LONG
��^�j�Y�|�P���O�M�G����^��, �a�W���\�F�@�Ǥp�֮�,
�A�����i�H�ݨ�X���p�����b�o����Y��. �A��F�@���s�Ө�
�o�Ӱj�Y���ਤ, �o�䦳�Ӱ��H���b�ӮƥL���p�ִ�.
LONG
    );
 set("exits",([
               "north":__DIR__"hall2",
               "east":__DIR__"hall4",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
