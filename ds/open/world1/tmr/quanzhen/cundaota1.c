// cundaota1.c �s�D��@�h
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�s�D��@�h");
        set("long", @LONG
�o�̬O�s�D�𪺤@�h�A�s�D��O��~���u�̤l�ΨӦs��g�Ѫ��a
��A�𤣰��A�O�Τ@���@�����j�C�۬�_�Ӫ��C�𤤪���l�]�O�ΫC
�۩Ҭ�A�ڻ����ҥH�Υ��Y���O���F�קK�����A�N���F���u�Ъ��g
�ѡC
LONG
        );
        set("exits", ([
                "south" : __DIR__"guozhendian",
                "westup" : __DIR__"cundaota2",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2780);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}