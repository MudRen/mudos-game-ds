inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", WHT"���Τs"NOR);
        set("no_fight", 1);
  set("light",1);
        set("long", @LONG

    ���b�s�}�U�ɶ������A�A��F�s�W�ɫo�ӫB�t�t�A���e�����Τs
�����|�A�A�Q�y�y���Qù������ۡA�����M�����B�A�C���F��ݹL�h�N
�O���u���}�v�F�C

LONG
        );
    set("exits",([
 "westdown" : __DIR__"room07",
 "east" : __DIR__"room10",
]));


        set("no_clean_up", 1);
setup();
        replace_program(ROOM);

}
