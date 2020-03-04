inherit MOBROOM;
void create()
{
	set("short", "�B�F���F�j��F");
	set("long",@LONG
�A�C�C������F�o�̡A�B�F�������F�j��b�o�̵����F�A�b�n�観
�@���Τl�A�b���P�򦳳\�h�e�Ӱ��[�^�����Ϊ��H���ιC�ȡA�Τl�P��
���\�h�X�ӡA�i��O����^���Ҹ����a�C
LONG
	);
	set("exits", ([
  "west" : __DIR__"beast2.c",
  "east" : __DIR__"beast4.c",
  "south" : __DIR__"herohouse.c",
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
	setup();
}
