inherit MOBROOM;
void create()
{
	set("short", "�p���");
	set("long", @LONG
�o�̬O�@�y�p�p�����A�b�o�̦��\�h���p�ʪ��A�]�����m�����a
�i�H���A�A�o�̪�����e�����n�䪺���O�ݦP�@�����A�]���@�Ǫ�
���s��A���L����K�ĴN�O�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"flurry18.c",
  "east" : __DIR__"flurry11.c",
]));
	set("no_clean_up", 0);
	set("chance",40);
	set("outdoors","land");
	set("mob_amount",4);
	set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
}));
	setup();
}
