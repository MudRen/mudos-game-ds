// Room: /u/k/kenshin/sha-zin-gu/room27.c

inherit ROOM;

void create()
{
	set("short", "�j�U[0m");
	set("long", @LONG
����F�j�U�A�ݨ�\�h�`���Y�{�e���ˤl�A�����O����A���ӭn
�n�n���ݲM���~�O�C�@�i�ӡA�N��ݨ�\�h�L���a���b��W�A�٦��@
�ǧL����b����誺�m���d���A�i�O�H�Q�찣�F�оɧ̤l�A�ۤv�]��
��R�I���ѡC
LONG
	);
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room28",
  "south" : __DIR__"room26",
]));
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
