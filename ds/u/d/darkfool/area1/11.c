// Room: /u/d/darkfool/area1/11.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�A�����b��W�����_���@�B��D�W�A�X�ө~�����ˤ�����A����
�I�A���_���h���G�O�@�j����v���ˤl�A�F���D���Y�����ݰ_��
���ǯS�O���p�ΡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"12",
  "southwest" : __DIR__"c1",
]));

	setup();
	replace_program(ROOM);
}
