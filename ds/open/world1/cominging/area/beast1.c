inherit MOBROOM;
void create()
{
	set("short", "�B�F���F�j���");
	set("long",@LONG
�o�̬O�B�F�����F�j�󤤥������A�b�o����W���\�h�q�F��䳣��
�Ӫ��~�a�H�A�b�o�̦��\�h�L�h�L�W�ꪺ������X�Ӧb�o�A�]���\�h�v
�ǤW�ҰO�������H�b���I�v�C
LONG
	);
	set("exits", ([
  "west" : __DIR__"beast.c",
  "east" : __DIR__"beast2.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	set("chance",35);
        set("mob_amount",3);
	set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	set("item_desc",([ "�X��" : "�X�ӤW�g�ۤ@�ιΧA�ݤ������p�f�r�C\n", ]));
	setup();
}
