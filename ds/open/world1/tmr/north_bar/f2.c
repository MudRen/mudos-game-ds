// Room: /open/world1/tmr/north_bar/f2.c

inherit ROOM;

void create()
{
	set("short", "�d�~�j�}-�}��");
	set("long", @LONG
�o�̪��a�W�Q���W�Y�����A�ӥB�Ѫ�O�S�Q���U���A�@���p
�ߴN�|�����Y�C�b�o�̡A�A�}�l�J��F�@�Ǭݰ_�ӤQ���z�p����
�~�A�@���`�N�A�e�N�|�ĹL�Ӱ�ŧ�A�A�аȥ��p�ߡI
LONG
	);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dinosaur.c" : 5,
  __DIR__"npc/dinosaur2.c" : 5,
  __DIR__"npc/dinosaur3.c" : 5,
  __DIR__"npc/mucus-odd.c" : 5,
]));

	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"f1",
  "southeast" : __DIR__"f4",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
