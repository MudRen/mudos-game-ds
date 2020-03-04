// Room: /open/world1/tmr/advbonze/hill7.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p-�W�s�p�|");
	set("long", @LONG
�A�����b�q���ⶳ�p�����p�|�A�p����Ǿ�L����K�A���ɪ���
����A����A�A�M���L����H�A�]�`�o�ۤ������A�~��j�j�q�L�C�o
�������n����V�L�h�i�U�ⶳ�p�A���_����V�h�O��`�J�L�B�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"hill5",
  "north" : __DIR__"hill8",
  "east" : "/open/world1/tmr/frost/footway",
]));
	set("no_clean_up", 0);
	set("outdoor", "forest");
	set("current_light", 5);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
