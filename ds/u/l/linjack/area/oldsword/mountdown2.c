#include <room.h>
inherit ROOM;
void create()
{
 set("short","���s�y�����W");
 set("long",@LONG
���e�񲴱�h, �ɬO�@���a�A���˪L, �o���ٯ�ݨ�X�Ӧ���
�L��, ���O�A�P��˪L�����G�N�S������H�b���ʤF. �J�ө�����
��, �s���W�䦳�@�ӫؿv��.
LONG
    );
 set("exits",([ "east":__DIR__"mountdown3",
                "northwest":__DIR__"mountdown1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}