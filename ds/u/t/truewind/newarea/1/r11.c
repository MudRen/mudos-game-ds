#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����U");
        set("long", NOR""+
"��i�F�T�Ӫ������U�A�U����۵L�ƪ��r�e�A�e�����K�H�Q�k\n"+
"�ܶ}�����A�����r���A�P�e�������s�y���Φ��L�������C���B�w�M\n"+
"�S���G�Ө���ټM�A�O�G�i�H�@��~�|�����A�@���A��¤Ѵ����\n"+
"�����C\n\n");
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"r10",
        "south" : __DIR__"r12",
        "down" : __DIR__"r07",
]));

	setup();
}