// Room: /d/xiangyang/biaoju.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "福威鏢局");
	set("long", @LONG
你來到一座結構宏偉的建築前，左右石壇上各插著一根兩
丈多高的旗杆，杆上青旗飄揚。右首旗子用金線繡著一頭張牙
舞爪的獅子，獅子上頭有一只蝙蝠飛翔。左首旗子上寫著“福
威鏢局襄陽分號”八個黑字，銀鉤鐵劃，剛勁非凡。入口排著
兩條長凳，幾名鏢頭坐著把守。
LONG );
	set("exits", ([
		"west" : __DIR__"eastroad1",
	]));
	set("objects", ([
//		"/d/fuzhou/npc/liu" : 1,
	]));
	setup();
	replace_program(ROOM);
}