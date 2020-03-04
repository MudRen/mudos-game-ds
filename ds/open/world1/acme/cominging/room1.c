// Room: /u/a/acme/area/room1.c

inherit ROOM;

void create()
{
	set("short", "�m�Z");
	set("long", @LONG
�o�̬O���Ԫ��x�L�b���n�Ϭݺު��a��A�]�O���ԩx�L�汵���a
��A��]�����H�ݦu�A�K�o���d�p���J�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"passage1",
]));
set("objects",([
    __DIR__"npc/guard2":2,
]));
	set("no_clean_up", 0);
        set("light",1);

	setup();
	replace_program(ROOM);
}
