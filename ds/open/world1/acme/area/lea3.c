// Room: /u/a/acme/area/lea3.c

inherit ROOM;

void create()
{
	set("short", "�j���");
	set("long", @LONG
�A���B�b�@��L�ڪ��j���A�|�P�����󲤬����j�A�樫�ɫKı�o��
�I�x���A�A�iť���K�ͦb�u���F�㪾�F��v���s�ۡA��o�ͮ�s�M�C�A�o
�{���W�����ۤ@�ǥզ⪺���Y�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lea2",
  "north" : __DIR__"lea4",
  "west" : __DIR__"lea6",
  "east" : __DIR__"lea10",
]));
	set("item_desc",([
 "���Y":"�A�J�Ӥ@�ݡA�o�{�o�ǥ��Y�ƦC���Q���W�ߡA���G�O�ӥ۰}�C\n",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("objects", ([
       __DIR__"npc/antelope" : 4,
    ]) );
	set("moon_club_enter",1); //������|�J�f
	setup();
	replace_program(ROOM);
}
