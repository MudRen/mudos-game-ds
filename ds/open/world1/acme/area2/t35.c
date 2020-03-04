// Room: /u/a/acme/area2/t35.c

inherit MOBROOM;

void create()
{
	set("short", "�խߦa��[�a�U�|�h]");
	set("long", @LONG
�A�����b�o���t���a�D�A�A�C�C�oı�a�W��~�~���A���G�V����
�Y�a���V��A�o�̪��Ů�]�V�ӶV���D�A���������A�O�H�@�áC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"t36",
  "south" : __DIR__"t34",
]));
	set("no_clean_up", 0);
        set("chance",60);
        set("mob_amount",1);    //�̦h�X�{�@�өǪ�
        set("mob_object",({     //�]�w�Ǫ��ɦW.
            __DIR__"npc/devil",
        }) );

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
    return ::valid_leave(me, dir);
}

