#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
�Ө�q�D���o�@�q�A�A���Gı�o�I�ᦳ�����W���F����ۧA�A
�L�W�����O���A������^�Y�ݡA�ϩ��N�|�ݨ��ۤv�û����Q�ݨ쪺�F
��A�A����F�X�y�A�~�򩹫e���h�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room1", 
  "north" : __DIR__"room3",
  "southwest" : __DIR__"room_2",
  "southeast" : __DIR__"room-2",]));
  set("light",1);
  set("objects", ([ /* sizeof() == 1 */
  // __DIR__"npc/boots-guard" : 1,
  __DIR__"npc/shield-guard" : 1,
  ]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
