// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST�CRoad�ISouth[2;37;0m");
	set("long", @LONG
�@���s��Centre�MShip����D�A���`���H�g�L�o����D�A�����|�d�N
��o����D���S���b�C����A�b�o�̯d�ߤ@�ݡA�N�|�o�{��@�ǥ��ɧA
�`�N����ӤS�O�A��Y���ơD�D�D�D�D�D
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dst2.c",
  "north" : __DIR__"dmid.c",
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
