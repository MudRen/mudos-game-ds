// Room: /u/k/kenshin/sha-zin-gu/room14.c

inherit ROOM;

void create()
{
	set("short", "�D�㩱");
	set("long", @LONG
�Ө�F�D�㩱�A�ݨ캡�B�ͬ��Ϋ~�A���e�@��A�ݨ�@�d�ƺ���
�D��A�V�O�@�ݡA���O�Z�L�֦����öQ�F��A�߸̷Q�Q�������ǪF��
���h�ֻ��ȧr?
LONG
	);
	set("current_light", 2);
	set("light", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/npc/itemboss" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
