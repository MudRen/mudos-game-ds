#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�a�U���D");
         set("long", NOR""+
"���⤣�������A�º������a�U���D�A�o�O�q�ϩ~���M�q�u��H��\n"+
"�ͪ������t�ΩҦb���a��A�@���@�����޽u�����b�|�P��A�U���D��\n"+
"�����@�����D�A���G�O�~���D�n�������ӷ��C\n\n"+
"�@��"HIG"�����D(river)"NOR"�q�����y�L�h�C\n\n");
        set("current_light", 0);
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"pool04",
        "east" : __DIR__"pool06",
        "north" : __DIR__"pool05a",
        "northeast" : __DIR__"pool05b",
]));
        set("objects", ([ 
        __DIR__"npc/weasel.c" : 2,
        __DIR__"npc/rat.c" : 1,
]));
	setup();
}