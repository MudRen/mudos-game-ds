// Room: /u/a/acme/area2/t.c

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
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"t2.c",
  "up" : __DIR__"p11.c",
]));
    set("objects",([
              __DIR__"npc/bat" : 2,
   ]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="up" && !userp(me) && !me->query("__AUTO_MOVE__") )
                return notify_fail("���̥u�����a�~��i�h�C\n");
      if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
        return ::valid_leave(me, dir);
}
