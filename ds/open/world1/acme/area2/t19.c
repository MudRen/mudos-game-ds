// Room: /u/a/acme/area2/t19.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�G�h]");
	set("long", @LONG
�o�̤@�����¡A�|�P�@�L�O���A�u��N���Ӧ�A�o�̪����A�`
��A�R�o�A�V������l�A�̦n�������}�o�ӤH���Һ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"t20",
  "southwest" : __DIR__"t18",
]));
      set("objects",([
         __DIR__"npc/tung.c" : 1,
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

