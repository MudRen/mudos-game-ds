// Room: /u/s/sonicct/area/gate1.c

inherit ROOM;

void create()
{
	set("short", "Naboo����");
	set("long", @LONG
�o�̬ONaboo�n�䪺�����A�q�L�F�N�i�H���ӪŲ���L�a��
�h�C�A�ݨ즳�Ǥh�L�b�o�̺ި�H�s�A�K�o�H�̵o�ͷN�~�C�_��
�N�O�q��Naboo�����ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road1",
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