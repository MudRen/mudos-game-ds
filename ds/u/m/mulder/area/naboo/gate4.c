// Room: /u/s/sonicct/area/gate4.c

inherit ROOM;

void create()
{
	set("short", "Naboo����");
	set("long", @LONG
�q�L�o�D�����A�N�h��Naboo���̯������a��--�O�L�C����
�u���@�ǫi�������I���M��s�H���|�쨺�̡C�H�̳̦n�N�O����
�̻��@�I�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"road12",
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