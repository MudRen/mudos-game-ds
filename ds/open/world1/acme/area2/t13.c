// Room: /u/a/acme/area2/t13.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�G�h]");
	set("long", @LONG
�A���樫�b�o�`�����C���·t�a�D�A�a�D���t����A�O�A����ı
�o���ΪA�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"t14",
  "southeast" : __DIR__"t12",
]));
        set("objects",([
           __DIR__"npc/chi" : 1,
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

