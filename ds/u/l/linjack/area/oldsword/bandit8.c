#include <room.h>
inherit ROOM;
void create()
{
 set("short","�o����a");
 set("long",@LONG
�S�q�L�F�@�q��L, �Ө�F�t�@���L���Ŧa�W, ���[�e�o��
���G���H�b������, �i�O�{�b�A�Ҩ��u�Ѥ@�Ǵݾl�����, �M�@
�Ǵݾl��K�s�����[�l. �A�o�{�_����G���ۨǤ���F��, �A�]
�\�i�H�L�h�ݬ�..
LONG
    );
 set("exits",([ "north":__DIR__"bandit9",
                "west":__DIR__"bandit7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
