// Room: /u/a/acme/area2/t36.c

inherit MOBROOM;

void create()
{
	set("short", "�խߦa��[�a�U�|�h]");
	set("long", @LONG
�A�����b�·t�L�񪺦a�D���A�a�D���S���A�n�������������A�V
�����Y�߸̶V�`�ȡA�o�Ѷ·t����y�O�A�����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"t37",
  "south" : __DIR__"t35",
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

