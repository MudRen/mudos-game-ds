// Room: /u/a/acme/area2/t18.c

inherit MOBROOM;

void create()
{
	set("short", "�խߦa��[�a�U�G�h]");
	set("long", @LONG
�o�̤@�����¡A�|�P�@�L�O���A�u��N���Ӧ�A�o�̪����A�`
��A�R�o�A�V������l�A�̦n�������}�o�ӤH���Һ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"t17",
  "northeast" : __DIR__"t19",
]));
	set("no_clean_up", 0);
set("chance",70);       
        set("mob_max",3);
        set("mob_amount",3);    //�h�̦h�X�{�T�өǪ�.
        set("mob_object",({     //�]�w�Ǫ��ɦW.
             __DIR__"npc/man",
        }) );

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
    return ::valid_leave(me, dir);
}

