#include <room.h>
inherit ROOM;
void create()
{
 set("short","�D��");
 set("long",@LONG
�o�̥H�F���N�O�j����, �ӭn���ӫ�������, �u�n�~
�򩹦�n��V���S�X�B���N��F, �A�����B�A��F�@��, 
���㪺�ݨ�ӫ��N��b���e, �ؿv�Q�����������[.
LONG
    );
 set("exits",([ "southwest":__DIR__"market2",
                "northeast":__DIR__"road5"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}