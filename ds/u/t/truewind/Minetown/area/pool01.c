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
        "up" : __DIR__"machinefield5",
        "east" : __DIR__"pool02",
]));

	setup();
}
