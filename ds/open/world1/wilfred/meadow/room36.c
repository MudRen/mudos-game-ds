
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",YEL"���ֻX�j�]-����"NOR);
  set("long", @LONG
�o�̬O�@���p�p���X�j�]�A�|�g�G�m���Q��²��A�b�@�Ǫ�����
��ۼư����P�C�⪺���������C
LONG
);
  set("exits", ([
  "south" : __DIR__"room33",
]));
  set("no_clean_up", 0);

        set("objects", ([ /* sizeof() == 1 */
"/open/world1/tmr/cow_area/tombstone.c" : 1,
]));
    
  setup();
  replace_program(ROOM);
}
