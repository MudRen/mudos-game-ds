#include <ansi.h>
inherit ROOM;
void create()
{
     set("short",HIC"�y����ѫ�"NOR);
     set("long",HIW"\n\t�Ө�o�̡A�N�O���P�z���߱��A�߶}�@�����O�I\n"
                   "\n\t�n�n���P�n�Ͳ�W�X�y��^.^��\n\n"NOR);
             set("exits", ([ /* sizeof() == 1 */
  "north" : "/u/j/jangshow/workroom",
]));
     setup();
}
