// Room: /u/a/acme/area/lea7.c

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
  "southeast" : __DIR__"lea9",
  "northeast" : __DIR__"lea8",
  "east" : __DIR__"lea6",
]));
        set("chance",65);
        set("mob_amount",3);
     set("mob_max",8);
        set("mob_object",({   
            __DIR__"npc/orangutan",
        }) );
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
}
