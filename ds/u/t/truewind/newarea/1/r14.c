#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���i��");
        set("long", NOR""+
"�o�O���i�ժF���A�����ﺡ�F�k�H�Ϊ������M��l�A�٦��@�Ǭ�o\n"+
"���ª��窫�A�@��@�󱾦b��W�A�ݨӬO��z�L�F�C�Ѫ�O�W�}�F�ѵ�\n"+
"�A���u�i�H�q�W�Y���������Ӷi�ӡC\n\n");

        set("current_light", 1);
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"r13",
]));
        set("objects",([
        __DIR__"npc/16" : 1,
]));
	setup();
}