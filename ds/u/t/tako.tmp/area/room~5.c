#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�}�]���Y");
        set("long",@LONG
�A����F�}�]�����Y�A�A�C�j����,�|�|�����A�A�ڵM�����۫H�A�ۤv��
�ݨ쪺�e���A�ӤH�����H�A�����������ͪ��A�L�ݰ_�Ӧ��G�ܤ��r�A�A�߷Q�G��
���~���s�n�O���s���H�H�A�@�Q��o�ӡA�N�����_���֪��D�A�u�Q�������}�o
��....�I�I
LONG
      );
        set("exits", ([ /* sizeof() == 1 */
  "out" :"/u/t/tako/area/room~4.c",
]));
    set("light",1);
set("objects", ([ 
"/u/t/tako/area/chi***yo.c" : 1,
]));
    set("no_clean_up", 0);
                set("outdoors","land");

        setup();
 replace_program(ROOM);
}



