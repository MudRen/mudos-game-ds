#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�o�̬O���ݪ��̧���A���U�@���A���a�U�ءA���Y�@��A�E��d���A
�u���o�̪��P��A��¶�������������A���د��t���i�I�Ǫ��Pı�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room1",
]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"statue" : 1,
]));
        set("outdoors","land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

