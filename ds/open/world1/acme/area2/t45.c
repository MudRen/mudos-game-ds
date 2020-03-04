// Room: /u/a/acme/area2/t45.c

inherit MOBROOM;

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
  "north" : __DIR__"t44",
  "east" : __DIR__"t44",
  "west" : __DIR__"t44",
  "south" : __DIR__"t44",
]));
        set("no_map",1);
	set("no_clean_up", 0);
        set("chance",70);
        set("mob_amount",2);    //�h�̦h�X�{�G�өǪ�.
        set("mob_object",({     //�]�w�Ǫ��ɦW.
         __DIR__"npc/mo",
        }) );

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
    return ::valid_leave(me, dir);
}

