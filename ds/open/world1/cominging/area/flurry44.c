inherit MOBROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�A�����b�@�ӫܼe������W�A����Ǧ��\�h���A�j���O�H����
�D�A�ҥH�b����W���|���@�Ǳ����������A��ѮɡA�b���䪺�֪��|
�}�X�@�������R����A��߮��ءC
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"flurry43.c",
  "south" : __DIR__"flurry39.c",
  "east" : __DIR__"flurry45.c",
  "northup" : __DIR__"flurry46.c",
]));
	set("no_clean_up", 0);
	set("chance",40);
	set("mob_amount", 2);
	set("mob_object",({
  __DIR__"npc/apprentice",
}));
	set("outdoors","land");
	setup();
}
