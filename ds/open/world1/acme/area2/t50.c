// Room: /u/a/acme/area2/t50.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�|�h]");
	set("long", @LONG
�A�����e�@�G�A�o�̿O���q���A��o�A�����C�����ӡA�|�P�ŵL
�@���A�u������W���Ӥp�o�O�A�èS���S�O���a��C
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/ju" : 1,
  __DIR__"npc/xie" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"t51",
  "south" : __DIR__"t48",
]));
set("light",1);
	set("no_clean_up", 0);

	setup();
}
