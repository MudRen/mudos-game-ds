inherit MOBROOM;
void create()
{
	set("short", "�B�F���n�j��̫n��");
	set("long",@LONG
�b�������B�A�N�ݨ�o�̦��\�h�q�_��j�ƪ��s�ӨӪ��H��, �O�H
�~���@���A�b�o�A�i��s�B�泣���@�I�x���A���L���n�A���@���ä�
�ֶ몺�p�����F�X�ӡA�b�o���_��O�n�j�󪺫n�ݡA���@�a�ܦ��W���v
�޳��b���A�Ӧb�n��h�O�B�F�����j���C
LONG
	);
	set("exits", ([
  "north" : __DIR__"bsouth3.c",
  "south" : __DIR__"bdoor.c",
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
