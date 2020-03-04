// Room: /u/a/acme/area3/p10.c

inherit ROOM;

void create()
{
	set("short", "�j�U");
	set("long", @LONG
�o�O�̬I�v���j�U�A�|�P��W���F�\�h�W�e�A�M�Ѫk�ֵ��A���e�觤
�۳\�h�j�H���A����٦��\�h�������Ѧb���A�����o�ͤF��ơA�n�Ұʳo
�ǤH�Ӧ��E�|�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p5",
]));
       set("light",1);
set("objects",([
    __DIR__"npc/shi" : 1,
 __DIR__"npc/general" : 1,
__DIR__"npc/aw" : 1,
__DIR__"npc/lee" : 1,
]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
