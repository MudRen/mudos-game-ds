#include <ansi.h>
#include <room.h>

inherit ROOM;
inherit DOOR;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
�o�̬O�j�Ӫ��a�U�K�ǡA�����ˤS���I����A�b�o�̵L�������
�A���⤣�������A���ݪ�ݳ��䤣��@�ӤH�A�uť�����~���r�r�s�n
�A���e���n���٦����A���W�O�^��j�Ӫ��j�U�C

LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room1", 
  //"down" : __DIR__"shiro-door",
  "up" : "/open/world1/moonhide/area/room4",
])); 
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        create_door("up","������","down",DOOR_LOCKED,"whitekey"); 
}

