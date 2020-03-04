#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
�A�ݨ�q�D�e�観�ǳ\�G���A���G���Ӽs�諸�ж��A�ߤ����T�y
�L�P�F�f��C�@������������u�A�����������g��o�̡A���H���Pı
�N���O�A�ʰ����I���a��A�����t�A�S�����c�ʡA�u�O�_�ǡC
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room3", 
  "north" : __DIR__"room5",
  "southwest" : __DIR__"room_4",
  "southeast" : __DIR__"room-4", 
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/boots-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

