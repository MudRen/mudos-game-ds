// Room: /u/s/sonicct/area/gate3.c

inherit ROOM;

void create()
{
	set("short", "Naboo����");
	set("long", @LONG
�L�F�o�D�F�����A�N��q��Naboo���j�˪L�C�ӳo�̦������y
��X�X�J�J�A�ݰ_�ӳo�Ӵ˪L�����ֳ��~�i�H����C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road9",
 "east" :"/u/m/mulder/area/naboo/jungle/jungle",
]));
		 set("objects",([
  __DIR__"npc/guard":1,
__DIR__"npc/guard1":2,
 ]));

	set("outdoors","land");
	set("no_clean_up", 0);
	
	setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="east" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}