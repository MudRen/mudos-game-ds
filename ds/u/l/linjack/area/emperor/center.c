#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s��");
 set("long",@LONG
�o�̬O�e���W���p�s��, �E���F���֤H, �]�]���o��֦�
�Q���j�q���u�c�M����, �p�G�A�����򪫸�ʥF, �i�H���ި�
�o�����.
LONG
    );
 set("exits",([ "south":__DIR__"market2",
                "north":__DIR__"market1",
                "west":__DIR__"market3",
                "east":__DIR__"road6",
                "southeast":__DIR__"road2_1"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}