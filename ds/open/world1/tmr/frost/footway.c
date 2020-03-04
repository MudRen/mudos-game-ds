// Room: /open/world1/tmr/frost/footway.c

inherit ROOM;

void create()
{
	set("short", "�̹D");
	set("long", @LONG
�o�O�@���[�g���ת��̹D�A���ۮp�y�ӿv�A���誺�D�����S�b�@����
�L�A�i�q���ⶳ�p���W�s�p�|�A���F���۴̹D�Ӧ�A�i��F�M�ⶳ�p�ۨ�
���t�@�y�s�p�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/world1/tmr/advbonze/hill7",
  "east" : __DIR__"footway2",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}
