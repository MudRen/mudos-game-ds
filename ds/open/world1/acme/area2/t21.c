// Room: /u/a/acme/area2/t21.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�T�h]");
	set("long", @LONG
�A���樫�b�o�`�����C���·t�a�D�A�a�D���t����A�O�A����ı
�o���ΪA�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"t20",
  "north" : __DIR__"t22",
]));
        set("objects",([
              __DIR__"npc/lesshand" : 2,
        ]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="eastup" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
        return ::valid_leave(me, dir);
}
