inherit MOBROOM;
void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�O�@���������u�����Y�A���Y�W�O���q���A�p�P���뤧�j�A���Y
�W�������i�X���T�T���s���³��A�Y�ۦa�W���U���̽\�A�]�i�R���@
�f�A���Y�W���γ��n�����Ǻ|�}�A�ä�í�w���ˤl�C

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"flurry25.c",
  "east" : __DIR__"flurry27.c",
]));
	set("no_clean_up", 0);
	set("chance", 60);
        set("mob_amount",4);
        set("mob_object",({
  __DIR__"npc/sparrow",
}));
	set("light",1);
	setup();
}
