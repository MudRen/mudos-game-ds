// Room: /u/a/acme/area2/t23.c

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
  "south" : __DIR__"t22",
  "north" : __DIR__"t24",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ghost" : 2,
]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
    return ::valid_leave(me, dir);
}

