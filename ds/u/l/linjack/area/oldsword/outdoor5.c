#include <room.h>
inherit ROOM;
void create()
{
 set("short","���۪����W");
 set("long",@LONG
�A�{�b���B���۪����W, �s�U���R���i�H�M�����ݨ�,
�o�Ӧa��O���۪����F��, �a��s�L, �C�s���F���˪L�i
�H�Ѧ��B�ʵ�.
LONG
    );
 set("exits",([ "west":__DIR__"outdoor4",
                "down":__DIR__"outdoor2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}