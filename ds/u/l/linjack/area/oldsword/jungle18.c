#include <room.h>
inherit ROOM;
void create()
{
 set("short","�}�ޫe");
 set("long",@LONG
����L�I���q�L�F���ǲr�~, �S���F�@�q�ɶ�, �A�Ө�@�B��
�����s�}���e, �s�}����ĭ�ä@�ѱj�j����, �O�A�b�~���N�w�g
���I�ݤ��L���, �ӥB�}�������O��....? �i�O�}�ު��J�f�Q�@��
���۵��צ�F.
LONG
    );
 set("exits",([ "southeast":__DIR__"jungle19",
                "north":__DIR__"jungle17",
                "west":__DIR__"jungle16",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}