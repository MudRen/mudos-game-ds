#include <room.h>
inherit ROOM;
void create()
{
 set("short","���۪����W");
 set("long",@LONG
�A�{�b���B���۪����W, �s�U���R���i�H�M�����ݨ�,
��ӥ��۪��u���o�̪����U��~���q�D���̭���, �]���o
�䪺���u�]�S�O�Y�K, ���\�h���ͽó��b�o�䨵��.
LONG
    );
 set("exits",([ "east":__DIR__"outdoor5",
                "west":__DIR__"outdoor6",
                "down":__DIR__"outdoor1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}