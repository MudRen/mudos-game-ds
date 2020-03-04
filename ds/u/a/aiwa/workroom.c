// Room: /u/a/aiwa/workroom.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIG+"�@�~���"+NOR);
	set("long", @LONG
�A�Ө�F�@�Ӭݦ��Ѱ󪺦a��C���p���B���y���A���@����a�A
�󦳤@�y�p��A�b�򤤦��@���p�ΡC�O���O�P�H��b�̭��O�H�A
�i�H�i�h(enter)�ݬݡI
LONG
	);
	set("objects", ([
            ]));

	set("light", 1);

	set("exits", ([ /* sizeof() == 7 */
		"enter"	: __DIR__"home",
		"wiz"	: "/d/wiz/hall1",
		"shengsan" : "/u/s/shengsan/workroom",
		"luky"	: "/u/l/luky/workroom",
            ]));

	set("valid_startroom",1);
	set("no_clean_up", 0);
       	setup();
        call_other("/obj/board/aiwa_b", "???");
}

void init()
{
	add_action("do_enter","enter");
}

void do_enter()
{
	object me;
	me = this_player();
	tell_object(me,"\n\n[1;37m�A���L���䪺�p���A��F�p�Ϊ����f�A������V��\n");
	tell_object(me,"���ɭԡA���M�T�_�F�@�}�ȹa��M�����n����[m\n\n");
	tell_object(me,"[1;35m�w����{��ؤu�@��[m\n\n\n");
}
