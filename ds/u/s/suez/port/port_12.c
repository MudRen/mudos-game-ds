#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�p�|");
        set("long",@LONG
�q�o�̩��_�N�O�ĺ��Ĵ��_�誺�X�f�F�A�M��f���䪺�پx���P�A�o
�̦w�R�h�F�C�X���ө������b�p�|����ǡA��۷�a�~���ݭn����`�Ϋ~
�A���䪺��W�i�i���ε۴X���ߡA�D���ۤȫ᪺�y���C
LONG 
);
        set("exits",([
            "west":__DIR__"port_11",
            "north":__DIR__"port_13"
                ]));
        set("world","world1");
        set("outdoor","land");

        setup();
        replace_program(ROOM);

}
