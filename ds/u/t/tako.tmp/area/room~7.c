#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�}�]");
        set("long",@LONG
�o�̬O�}�]������,�A�Pı�Y�����ū׺����U���F,�A�J�Ӥ@
�@,�e���O�@�j�����B,�A�������]�F�L�h.....�A�C�B�b�B
�줧�W,���@�������ɶ�,���ż����Pı�N�S�F,�u���@�ѨG
�ߦB�D���κZ�P,�A�ݨ�@�췡���ʤH���k�l�N���b�e����
���B
LONG
);
        set("exits", ([ /* sizeof() == 2 */
  "west" :"/u/t/tako/area/room~8.c",
  "east" :"/u/t/tako/area/room~6.c",
]));
    set("light",1);
set("objects", ([ /* sizeof() == 1 */
"/u/t/tako/area/girl.c" : 1,
]));      
  set("no_clean_up", 0);
                set("outdoors","land");

        setup();
        replace_program(ROOM);
}





