#include <room.h>
inherit ROOM;
void create()
{
 set("short","�K�}�ϫe��J�f");
 set("long",@LONG
�A���e�Ҩ����N�O���_���K�}�ϤF, �ǻ������K�Ӱ}��, �i�O
�A�b�o�ة��t�����Ҥ��򥻵L�k�����Ӱ}��, �Y�O�_�M�i�J����
�|���o����ӥX, �̦n�O�p�߬���.
LONG
    );
 set("exits",([ "west":__DIR__"secret1_8",
                "southeast":__DIR__"secret6_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
