// Room: /u/k/kenshin/sha-zin-gu/room12.c

inherit ROOM;

void create()
{
	set("short", "�Z���E");
	set("long", @LONG
�@���i�o�a�Z���E�A�Kť��@���j�����K�n���M����۩I���ʶR
�Z�����H�A�����K�E�@���H�ӡA�ë����@����h�A�N�O����L�ۡA��
���O�_�u�O�p���C
LONG
	);
	set("outdoors", "land");
	set("current_light", 2);
	set("light", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/npc/wpboss" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"room9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
