#include <path.h>
inherit ROOM;

void create()
{
        set("short", "�ɿ��n����");
        set("long", @LONG
�o�O�ɿ������n�����A�����f�U�E���ۦU���u�c�A�s��ۦU���U�˪��s
�A�f�~�A�۷����x�ڡI�ɿ��v�w�}�n�A�A�i�H�ݨ��@���w�M�����H�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"street6",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/garrison" : 4,
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);

        setup();
        replace_program(ROOM);
}

