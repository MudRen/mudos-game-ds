#include <room.h>
inherit ROOM;
void create()
{
 set("short","�������a");
 set("long",@LONG
�o�Ө��|�P���s���ä��~�k, �u�n���A���u��, �i�H��
�e�������}�o�Ӥs��, �Ӧa�W���G���ǫܫp�����, �����D��
�ۤ���, �A���F�褣���B���G���@�ӳq��.
LONG
    );
 set("exits",([ "south":__DIR__"outdoor8",
                "west":__DIR__"outdoor11",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}