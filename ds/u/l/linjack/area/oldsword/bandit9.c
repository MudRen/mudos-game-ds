#include <room.h>
inherit ROOM;
void create()
{
 set("short","�]���e");
 set("long",@LONG
���F�X�B��, �A�Ө�F�@�Ӥ�s�]�����e��, �o�䪺�L��
�ݰ_�ӴN�}���F����, �A�w�g�i�H�M��������|�P������. �e
�����G�]�O�@����a, �����w�O����g��s��, �̦n�����}�o
��, �γ\�٦����}�����|.
LONG
    );
 set("exits",([ "north":__DIR__"bandit10",
                "south":__DIR__"bandit8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
