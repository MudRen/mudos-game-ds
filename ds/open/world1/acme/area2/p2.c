// Room: /u/a/acme/area3/p2.c

inherit ROOM;

void create()
{
	set("short", "�x�|");
	set("long", @LONG
�A�����b���j���x�|�A�b�x�|�̦��\�h�ĵ��b���A�A�b�A���_��ؤF
�@���j�Q��A�ӪF�_��h�i�ݨ��@�Ӥp���l�C
LONG
	);
        set("light",1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"p3",
  "south" : __DIR__"p",
]));
set("objects",([
   __DIR__"npc/general2" : 1,
]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
