// Room: /u/a/acme/area2/t6.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�@�h]");
	set("long", @LONG
�o�̬O�խߦa�����a�U�@�h�A�@�˩��t�����A�|�P���o�õL�G�ˡA������
���iť�����~���H���n�A�O�A���H�ӷX�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"t5",
  "east" : __DIR__"t7",
]));
        set("objects",([
           __DIR__"npc/bear" : 2,
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

