#include <room.h>
inherit ROOM;
void create()
{
 set("short","�e���e");
 set("long",@LONG
�o��}�l���ǹ������n��, �H�]�}�l�E��, �e�����G
�O�@�Ӥe���f, �b�e���f�W���\�h�����Q, �@���ݥh���x
�D�Z, �Ӧb�e���᭱Ũ����, �O�@�y�۷��j������.
LONG
    );
 set("exits",([ "southwest":__DIR__"road6",
                "north":__DIR__"road4"]));
 set("no_clean_up", 0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}