// Room: /u/a/acme/area2/t12.c

inherit MOBROOM;

void create()
{
	set("short", "�խߦa��[�a�U�G�h]");
	set("long", @LONG
�A���樫�b�o�`�����C���·t�a�D�A�a�D���t����A�O�A����ı
�o���ΪA�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"t13",
  "southeast" : __DIR__"t11",
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

