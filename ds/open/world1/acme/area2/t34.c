// Room: /u/a/acme/area2/t34.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�|�h]");
	set("long", @LONG
�A�����b�o���t���a�D�A�A�C�C�oı�a�W��~�~���A���G�V����
�Y�a���V��A�o�̪��Ů�]�V�ӶV���D�A���������A�O�H�@�áC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"t35",
  "west" : __DIR__"t33",
]));
    set("objects",([
       __DIR__"npc/si" : 1,
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

