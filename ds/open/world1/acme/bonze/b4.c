// Room: /open/world1/acme/bonze/b4.c

inherit ROOM;

void create()
{
	set("short", "�W�s�p��");
	set("long", @LONG
�A���b�o����s�D���A�r�K�����A�|�����šA�@�����I�A����
�q�����B�ǨӴX�n���T�p�A��o��~���Y�D�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"b3",
  "southup" : __DIR__"b5",
  "north" : __DIR__"b18",
]));
    set("objects",([
   __DIR__"npc/old_beggar": 1,
   ]) );
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
