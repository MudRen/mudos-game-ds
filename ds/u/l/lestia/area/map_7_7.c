// Room: /u/l/lestia/area/map_7_7.c

inherit ROOM;

void create()
{
	set("short", "�]�O�̻�");
	set("long", @LONG

�o�̰g���ۤ@�ѥR���զ⪺����A�q�A���|�P�w�w�ɰ_���b���B�ӥh�A
���𤤳z�S�X�����H��A�·t���N�������A���T�����o�ݡA�A��۫e
��@����M�A��A�^�L���ɡA�A�o�{�A�w�g�`�`�����b�o���˪L�����F�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"map_7_6",
  "east" : __DIR__"sn1",
  "south" : __DIR__"map_8_7",
  "north" : __DIR__"map_6_7",
]));
	set("current_light", 3);

	setup();
}
int valid_leave(object me, string dir)
{
       object obj;
me = this_player();
 if( dir=="west")      //&& !wizardp(me))
        {
if( me->query("level") < 10) return notify_fail("�A�ΤO�����]�O�̻ٽĹL�h�A���O�]���O�q�����ӳQ�u�F�^�ӡC\n");
}
        return ::valid_leave(me, dir);
}
