// Room: /u/a/acme/area2/t25.c

inherit MOBROOM;

void create()
{
	set("short", "�խߦa��[�a�U�T�h]");
	set("long", @LONG
�A�A�e��ƤV�A�a�D��M�����A�����}���Ӧ�A�V�V�e��A�s�y
�V�C�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"t26",
  "west" : __DIR__"t24",
]));
	set("no_clean_up", 0);
set("chance",70);       
        set("mob_max",3);
        set("mob_amount",3);    //�h�̦h�X�{�T�өǪ�.
        set("mob_object",({     //�]�w�Ǫ��ɦW.
            __DIR__"npc/ghost2",
        }) );

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
    return ::valid_leave(me, dir);
}
