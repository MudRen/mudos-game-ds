#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�Ŧa"NOR);
        set("long", @LONG
�o�̬O�ӳ������@�B�Ŧa�A�ݰ_�ӻᳱ�˪��C�b�o�Ŧa�٦��\�h���
��󪺡A�����H�J���F�A�A�߸̤��T���o�ǥͪ��d�s��!!
LONG
        );

           set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"room3",
            ]));
        
       set("no_clean_up", 0);
        set("no_light", 1);
       set("valid_startroom",1);

        setup();
        replace_program(ROOM);
}


        
