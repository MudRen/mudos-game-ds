#include <room.h>
inherit ROOM;
void create()
{
 set("short","�������a");
 set("long",@LONG
�o�Ө��|�P���s���ä��~�k, �u�n���A���u��, �i�H��
�e�������}�o�Ӥs��, �A���_�褣���B���G���@�ӳq��.
LONG
    );
 set("exits",([ "north":__DIR__"outdoor11",
                "east":__DIR__"outdoor8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}