#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"ù�~�ԹD"HIG"�Ĥ@�h"NOR);
        set("long", @LONG
�o�̴N�O�ⶳ�x���T�a�uù�~�ԹD�v�A�̭��¯���a���@�I�I�����ơA
�b���٦��@�ǿU�N��������A�Q���O���ǤH�n�_�]��ӬݬݳQ�b�̭����r�V�@
�f�������n�᪺�ݴ�A�ݰ_�Ӯ��Ƥ����C
LONG

        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
        "north" : __DIR__"a5",
]));
        set("outdoors", "land");

        setup();
        replace_program(ROOM);
}
