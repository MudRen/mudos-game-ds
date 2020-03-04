// Room: /u/a/acme/area2/t24.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�T�h]");
	set("long", @LONG
�A���樫�b�o�`�����C���·t�a�D�A�a�D���t����A�O�A����ı
�o���ΪA�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"t23",
  "east" : __DIR__"t25",
]));
	set("no_clean_up", 0);
	set("mob_object", ({ /* sizeof() == 1 */
   __DIR__"npc/ghost2.c",
}));
	set("mob_amount", 3);
	set("chance", 70);

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
    return ::valid_leave(me, dir);
}

