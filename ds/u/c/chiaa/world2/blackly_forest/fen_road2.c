//u/c/chiaa/world2/blackly_forest/fen_road2.c

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
        set("exits", ([ /* sizeof() == 5 */
     "east"       : __DIR__"fen2",         //�h�A2
     "west"       : __DIR__"bridge",       //�p��
     "north"      : __DIR__"fen_road1",    //�h�A�p��1
     "southeast"  : __DIR__"fen3",         //�h�A3
     "northeast"  : __DIR__"fen1",         //�h�A1
]));
       
        setup();
replace_program(ROOM);
}
