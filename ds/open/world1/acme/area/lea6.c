// Room: /u/a/acme/area/lea6.c

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
  "west" : __DIR__"lea7",
  "north" : __DIR__"lea8",
  "south" : __DIR__"lea9",
  "east" : __DIR__"lea3",
]));
        set("chance",65);
        set("mob_amount",4);   
     set("mob_max",12);
        set("mob_object",({   
            "/open/mob/mosquito",
               }) );
	set("no_clean_up", 0);
      set("outdoors","land");

	setup();
}
