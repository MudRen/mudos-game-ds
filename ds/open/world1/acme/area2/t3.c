// Room: /u/a/acme/area2/t3.c

inherit MOBROOM;

void create()
{
	set("short", "�խߦa��[�a�U�@�h]");
	set("long", @LONG
�o�̬O�խߦa�����a�U�@�h�A�|�P���t�����A���k�G��������W�U���@��
���o�O�y�A���õL�o�i�U�N�A���a�j���ۤ@�Ѥg��A�c������A�a�W���õۤ@
��Ͱ��A�o���O�H���A�ӬO�ʪ����e���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"t4",
  "south" : __DIR__"t2",
]));
	set("no_clean_up", 0);
set("chance",70);
        set("mob_max",3);
        set("mob_amount",3);    //�h�̦h�X�{�T�өǪ�.
        set("mob_object",({     //�]�w�Ǫ��ɦW.
           __DIR__"npc/chicken",
        }) );

	setup();
}

int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
    return ::valid_leave(me, dir);
}

