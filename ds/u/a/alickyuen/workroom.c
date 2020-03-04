#include <ansi.h>
#include <room.h>

inherit ROOM;

string *guest = ({ });
string *exits = ({
	"/d/wiz/hall1",
	"/u/c/cominging/workroom",
	"/u/b/baal/workroom",
});
string random_exit();

void create()
{
	set("short", HIR"Released Workroom "HIY"[Ver 1.0 beta]"NOR);
	set("long", @long
�o�O�@�ӭ觹�����u�@���A�O�ѦU��Ův�@�֥Ϊ��ж��A�Ŷ���
�]��Ӫw����ѡA�ͬ��y���A²���O�Ův�������t�a�A�t�a��������
��C
long);
	set("exits", ([
//                "out" : (: random_exit :),
//                "out" : exits[random(sizeof(exits))],
		"qc" : __DIR__"qcroom",
		"enter" : __DIR__"programming",
		"test" : "/open/world1/alickyuen/match/entrance",
			"north" : "/u/t/tmr/workroom",
		"dd" : __DIR__"down_city/map_0_7",
	]));
	set("objects", ([
		__DIR__"killerjob" : 1,
		"/u/s/shengsan/npc/bluemaster" : 1,
		"/open/world1/acme/area/npc/fanny.c" : 1,
	]));
	set("valid_startroom", 1);

	setup();
	load_object("/obj/board/alickyuen_b");
}

void init()
{
}

string random_exit()
{
	return exits[random(sizeof(exits))];
}
