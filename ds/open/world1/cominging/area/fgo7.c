inherit ROOM;

void create()
{
	set("short", "�˪L�X�f��");
	set("long", @LONG
�o�̬O�˪L���X�f����F�A�A�ߤ��]�ּ֤F�\�h�A�]���ΦA�P���~
����F�A��_��N�O�˪L���X�f�F�A�]�i�H��O�J�f�A���e�������{
�Ѩä������A���G���Ǯ`�ȡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"fgo6.c",
  "west" : __DIR__"fgo8.c",
]));
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(3),
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
