// Room: /u/a/acme/area2/t2.c

inherit ROOM;

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
  "north" : __DIR__"t3",
  "west" : __DIR__"t.c",
]));
     set("objects",([
        __DIR__"npc/dog" : 2,
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

