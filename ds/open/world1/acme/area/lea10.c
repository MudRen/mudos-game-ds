// Room: /u/a/acme/area/lea10.c

inherit MOBROOM;

void create()
{
	set("short", "�j���");
	set("long", @LONG
�A���B�b�@��L�ڪ��j���A�|�P�����󲤬����j�A�樫�ɫKı�o��
�I�x���A�A�iť���K�ͦb�u���F�㪾�F��v���s�ۡA��o�ͮ�s�M�C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"lea3",
  "north" : __DIR__"lea12",
  "south" : __DIR__"lea13",
  "east" : __DIR__"lea11",
]));
        set("chance",80);
        set("mob_amount",3);
     set("mob_max",15);
        set("mob_object",({   
            "/open/mob/bug",
        }) );
	set("no_clean_up", 0);
       set("outdoors","land");

	setup();
}
