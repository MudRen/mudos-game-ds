#include <room.h>
inherit ROOM;
void create()
{
 set("short","�K�}�ϫ��J�f");
 set("long",@LONG
�A���e�Ҩ����N�O���_���K�}�ϤF, �ǻ������K�Ӱ}��, �i�O
�A�b�o�ة��t�����Ҥ��򥻵L�k�����Ӱ}��, �Y�O�_�M�i�J����
�|���o����ӥX, �̦n�O�p�߬���.
LONG
    );
 set("exits",([ "north":__DIR__"secret6_6",
                "out":__DIR__"outdoor13",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
