#include <room.h>
inherit ROOM;
void create()
{
 set("short","�V���󤺭b�j��");
 set("long",@LONG
�o��N�O�V���󤺭b���j��, �Q���������[, �W�����κ�
�s����R, �����D�O�X�ۨ��a�J��a���W�@, ���W��Ӫ����e
�o�ݮݦp��, ���e���|���W�ͽò������q���V�A��§�Цw, ��
�ӳ��Q���ªZ, �ݨӳo�V����G�u��²��.
LONG
    );
 set("exits",([ "north":__DIR__"inroom18",
                "south":__DIR__"outroom4",
                 "west":__DIR__"outroom2",
                 "east":__DIR__"outroom3",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}