// Room: /u/a/acme/area/room2.c

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
  "west" : __DIR__"passage3.c",
]));
set("objects",([
    __DIR__"npc/guard2" : 2,
]));
	set("no_clean_up", 0);
        set("light",1);

	setup();
	replace_program(ROOM);
}
