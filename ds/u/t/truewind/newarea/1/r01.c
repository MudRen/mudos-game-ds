#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�p�m�U");
        set("long", NOR""+
"�o��N�O�K���Ӫ��j�U�A�H���p�m�U�A�Ӧ����̤H���Ȧh�b�y�s\n"+
"�Ѫ�A���O�ŭ��n���a�n�P�y�N���H�ĤƨC�Өk�H�����U�A�󤣭n��\n"+
"���R���˹��M�����F�A�o�N�O��¤ѼӪ��ȫȴX�G���|�즹�a�@�C��\n"+
"��]�C\n\n");

        set("current_light", 1);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"rd",
        "north" : __DIR__"r02",
        "west" : __DIR__"r04",
]));
        set("objects",([
        __DIR__"obj/desk01" : 1,
        __DIR__"npc/07" : 1,
]));
	setup();
}