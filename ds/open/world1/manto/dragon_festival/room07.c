inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", WHT"���Τs"NOR);
        set("no_fight", 1);
  set("light",1);
        set("long", @LONG

    ���b�s�}�U�ɶ������A�A��F�s�W�ɫo�ӫB�t�t�A���e�����Τs
�����|�A�A�Q�y�y���Qù������ۡA�����M�����B�A�C����_�ݥh�i��
��@�F�l�����Qù���`�A�Q���K�O���u�W���F�v�F�C

LONG
        );
    set("exits",([
 "westdown" : __DIR__"room06",
 "eastup" : __DIR__"room09",
]));


        set("no_clean_up", 1);
setup();
        replace_program(ROOM);

}
