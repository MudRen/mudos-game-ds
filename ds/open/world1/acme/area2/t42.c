// Room: /u/a/acme/area2/t42.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�|�h]");
	set("long", @LONG
�o�̥|�P�����g���A���פF�A�����u�A���⤣�������A���G���
�����٬O�b��a�A�B���ɦ��@�D�N�N�������n�ۧA�@�A�A���T�ߤ��o
��C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"t43",
  "east" : __DIR__"t44",
  "west" : __DIR__"t41",
  "south" : __DIR__"t43",
]));
        set("no_map",1);
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
    return ::valid_leave(me, dir);
}

