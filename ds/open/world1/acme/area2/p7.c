// Room: /u/a/acme/area3/p7.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�O�@�y�����A�O�ΫC�ۿj�ҫسy�Ӧ����A�۷��T�A�q�������U��
�i�ݨ��p�Q�t�b���Y���Y�������A���U�h���۷m���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"p8",
  "west" : __DIR__"p6",
  "south" : __DIR__"p11",
]));
        set("light",1);
set("objects",([
   __DIR__"npc/lee2" : 1,
]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
