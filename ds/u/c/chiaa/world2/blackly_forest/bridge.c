//u/c/chiaa/world2/blackly_forest/bridge.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "��");
        set("long", @LONG
�A�����b�˪L���@�y���W,�o�y���ܤ[�H�e�N���F,
�w�g�۷�����,�ҥH���_�ӷn�n�̮�,
�`�Ȥ@�Ӥ��p�߫K�|�L�F�U�h!!
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
     "east"  : __DIR__"fen_road2",           //��h�p��2
     "west"  : __DIR__"road7",              //�L���p��7
]));
       
        setup();
replace_program(ROOM);
}

