#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIG"��ȷ|��"NOR);
        set("long",@LONG
�o�O�ĺ��Ĵ���~���Ψӵ��M�ȯɡA�������|�A�ѨM���@�ƶ��B���G
�U�بƱ����a��C���O�H���ĺ��Ĵ����o�i�A�o�̪��\�ລ�����Q���N�F
�A���M�W�q�W�o�̤��O�ĺ��Ĵ�����F���ߡC
LONG 
);
        set("exits",([
            "west":__DIR__"port_06",
                ]));
        set("objects",([
            __DIR__"npc/lucy":1,
                ]));

        set("world","world1");
        set("no_fight",1);
        set("no_magic", 1);
        set("light",1);
        setup();
        replace_program(ROOM);

}
