#include <room.h>
inherit ROOM;
void create()
{
 set("short","�o����a");
 set("long",@LONG
�S�q�L�F�@�q��L, �Ө�F�t�@���L���Ŧa�W, ���[�e�o��
���G���H�b������, �i�O�{�b�A�Ҩ��u�Ѥ@�Ǵݾl�����, �M�@
�Ǵݾl��K�s�����[�l.
LONG
    );
 set("exits",([ "east":__DIR__"bandit8",
                "southwest":__DIR__"bandit6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}