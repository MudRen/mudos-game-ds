#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"���F�۫�"NOR);

 set("long",@LONG
�A�@����o���۫�, �N�Q�H�̵���¶, �o�̪��Ю{�����k�k, �Χ���
��, �ѳ���۱��Ī���A, �ݨӭ�~�b�j�U�ݨ쪺�ħ�, �N�O�L�̧V�O��
���G�F, �o�̤H�����������, �����p�n�ӻy, �����������n, �����ͤ�
���a, �L�ܤ���, �]�L�ܤ��n, ���L, �j�����O�b�Q�׭�~���ĩҵo�ͪ�
���, �p�G�����F�L�̨��W���Ĩ�����, �ˬO�i�H���U��ť�@ť.
LONG
    );
 set("exits",([ "south":__DIR__"guild1", 
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

