// Room: /u/s/slency/area/ugelan/wood7.c

inherit ROOM;

void create()
{
	set("short", "�˪L�`�B");
	set("long", @LONG
�b�o�̧A�o�{���\�h�p��Χ����b��L���A����������N�L�����
�ݨӦ����֪��H��b�o�����K���p�����̡A���L�q�|�P�I�R���{�׬ݨ�
�A�o�ӧ����̲{�b���Ӥ@�ӤH�]�S���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wood6",
]));
	set("objects", ([ /* sizeof() == 1 */
	 __DIR__"npc/bandit1" : 3, 
]));
	set("outdoors", "forest");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
