// Room: /u/s/sonicct/area/gate2.c

inherit ROOM;

void create()
{
	set("short", "Naboo����");
	set("long", @LONG
�A�e���O�@�D���j�������A����Ӧu�æb���e�t�d�}���C
�A�ݨ��@�����W�Q�����g�o�D�����i�J�Ӯc�A�ӧA�u�i�b�D����
���[�ݡC�o�̪��n��O�q�h�����ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road6",
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
