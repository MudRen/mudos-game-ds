#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����U");
        set("long", NOR""+
"�o��O�T�Ӫ������U�A�U����۵L�ƪ��r�e�A�e�����K�H�Q�k\n"+
"�ܶ}�����A�����r���A�P�e�������s�y���Φ��L�������C���B�w�M\n"+
"�S���G�Ө���ټM�A�O�G�i�H�@��~�|�����A�@���A��¤Ѵ����\n"+
"�����C\n\n");
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"r09",
        "north" : __DIR__"r11",
        "up" : __DIR__"r13",
]));
	setup();
}