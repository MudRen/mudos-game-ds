// Room: /u/a/acme/area3/p15.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�O�@�����СA�o�̹}�i�۳\�h�@���A�γ\�A�i�H�X�ۥD�H���`�N��
�������o�X�Ǧ^�h�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"p14",
]));
       set("light",1);
set("objects",([
    __DIR__"npc/general3.c" : 1,
    __DIR__"npc/horse" : 1,
    __DIR__"npc/horse2" : 1,
]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
