// Room: /u/a/acme/area3/p17.c

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�o�O�@���p�СA�p�и���J�]�ּ˼˭ѥ��A�o�̪����u�A���b�N�۷�
�ƤU�s���p��A����|���A�O�A���C�T�ءC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p16",
]));
set("objects",([
   __DIR__"npc/general4" : 1,
   __DIR__"npc/ma" : 1,
]) );
       set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
