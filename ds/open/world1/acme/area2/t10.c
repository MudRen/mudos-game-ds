// Room: /u/a/acme/area2/t10.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�@�h]");
	set("long", @LONG
�o�̬O�խߦa�����a�U�@�h�A�|�P���t�����A�������ˡA�b�A���Ǯg�Ӥ@
�D�N�N�������A�O�A�P��L�����O�A�����O�_�~�򩹫e��C�b�A���e������
�ݨ������k�G�ƪ��j�۬W�A�۬W�򦨤@�Ӷ��A�b�۬W�������ө��U������C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"t9",
  "eastdown" : __DIR__"t11",
]));
        set("objects",([
         __DIR__"npc/wu" : 1,
       ]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="eastdown" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
        return ::valid_leave(me, dir);
}
