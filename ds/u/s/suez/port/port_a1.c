#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",BLU"�O��@��"NOR);
        set("long",@LONG
���m���Ŷ��A�L�L�����~�q�J�f�H�Υ��_�����F�i�ӡA�@�D�D�����q
���x�V�𤺪��U�Ө����C�@�ة_���S�������Pı�A���A���T�b�ߦb�o�̡C
�b���������a��A���@�y���j���۱�q���G�ӡC
LONG 
);      
        set("light",0);
        set("exits",([
            "up":__DIR__"port_a2",
	    "out":__DIR__"port_00"
                ]));
        set("world","world1");
        set("objects",([
             __DIR__"npc/bat":5,
                ]));

        setup();
        replace_program(ROOM);

}

