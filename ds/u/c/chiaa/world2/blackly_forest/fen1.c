//u/c/chiaa/world2/blackly_forest/fen1.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "�h�A");
        set("long", @LONG
�b�A���e���B���j�����h�A,�ݨӬ۷�����,
�b�h�A�P�򻮵M�i�����ְ��e,�h���W�]�����_�۩Ǫ����Ӫ�,
�]�i�ݨ�@�Ǥ����W���ͪ�,��Ӫh�����o�X���c�䪺�ͮ��,
�O�H�D�����R!!
LONG
        );
        set("exits", ([ /* sizeof() == 3 */     
     "west"       : __DIR__"fen_road1",      //�h�A�p��1
     "south"      : __DIR__"fen2",           //�h�A2
     "southwest"  : __DIR__"fen_road2",      //�h�A�p��2
]));
       
        setup();
replace_program(ROOM);
}