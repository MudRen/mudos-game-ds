// Room: /u/t/truewind/Minetown/area/leaderroom1.c

inherit ROOM;

void create()
{
	set("short", "�������׫�");
	set("long", @LONG
�W�F�G�ӡA�����i�H�ݨ즳�@�����A�������q�����s���C�ж�
�k�観�@�i�ɡA�ɾQ�O�ê��C���観���d�M�@�Ӥp�p���O�I�c�C����
���Ӥp�p���}��(button)�����D������γ~�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"leaderroom",
]));

	setup();
	replace_program(ROOM);
}
