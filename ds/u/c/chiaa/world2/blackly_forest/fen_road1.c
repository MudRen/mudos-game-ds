//u/c/chiaa/world2/blackly_forest/fen_road1.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "�h�A�p��");
        set("long", @LONG
�A�����b�@���d�פp��,�y���`�N�K�|���b�䤤,
�Ů��ƴ��۴c�����D���h��,���H�۷��ΪA!
�n�O���p�ߧl�J�L�h���h��,�u�Ȧ��w���g���٤H��!
���F�����B�i�ݨ�@�B�h�A�C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
     "east"       : __DIR__"fen1",         //�h�A1
     "south"      : __DIR__"fen_road2",    //�h�A�p��2
     "northwest"  : __DIR__"parting",      //���[��
]));
       
        setup();
replace_program(ROOM);
}
