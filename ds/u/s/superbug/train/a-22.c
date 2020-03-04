// Room: /u/s/superbug/train/a-22.c

inherit ROOM;

void create()
{
	set("short", "教堂");
	set("long", @LONG
你的眼前忽然出現了一座輝煌的教堂，四處滿是虔誠的教徒，台上正
有一位莊嚴的神父正在講道，你不禁懷疑這是否是真的，你輕輕的觸摸旁
旁邊的人，你的手竟然穿越了過去，仔細一瞧，原來都是旁邊的投影機產
生的幻影。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"a-6.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
