// Room: /u/a/acme/area/pathway.c
inherit MOBROOM;
void create()
{
	set("short", "�p��");
	set("long", @LONG
�o�̬O�@���p���A������ǯ�w�[�A����M���A���e�󦳤@��諸
�åۡA����i�H���}�o�̡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"pathway4",
  "west" : __DIR__"pathway1",
]));
        set("no_clean_up", 0);
        set("chance",65);
        set("mob_amount",2);    //�h�̦h�X�{�T�өǪ�.
        set("mob_object",({     //�]�w�Ǫ��ɦW.
            __DIR__"npc/snake",
        }) );
      set("outdoors","land");
	setup();
}
