#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�}�]");
        set("long",@LONG
�A�U���U�N,�Q���U�ۨӷ��@�|,���O�o�̧N���A�ۤ��U��,�A�}�l
�Q�a�F,�A���T�y�U�\��,�A�b�b����,���f�𪺻�:�ڤ@�w���|
����,��O�A���_�i�𩹫e��,���A�o�{...�w�g�S�����F

LONG
);
        set("exits", ([ /* sizeof() == 1 */
  "east" :"/u/t/tako/area/room~8.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 2 */
"/u/t/tako/area/angle_1.c" : 1, 
"/u/t/tako/area/angle_2.c" : 1,]));      
  set("no_clean_up", 0);
                set("outdoors","land");

        setup();
        replace_program(ROOM);
}







