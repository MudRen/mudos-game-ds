// Room: /u/a/acme/area2/t29.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�T�h]");
	set("long", @LONG
�A�A�e��ƤV�A�a�D��M�����A�����}���Ӧ�A�V�V�e��A�s�y
�V�C�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"t28",
  "south" : __DIR__"t30",
]));
         set("objects",([
            __DIR__"npc/tan" : 1,
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

