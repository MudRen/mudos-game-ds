inherit MOBROOM;
void create()
{
	set("short", "�_��");
	set("long",@LONG
�o�̪����񦳤@�a�p�p�����E�A���M�ä����W�A�i�H�����H�A�O��
�i�O�Ƥ@�ƤG���A�Z�ɹL�a�U�������H�A�쨺�a�����u�O�n�o���o�F�A
�b�n��O�_���Y�ݡA�Ӧb�_��]�٬O�_��A�b�A���Y�W���@��������
���b���C
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth2.c",
  "north" : __DIR__"bnorth4.c",
  "west"  : __DIR__"shop.c",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("chance",40);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	setup();
}
