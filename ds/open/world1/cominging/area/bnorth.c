inherit MOBROOM;
void create()
{
	set("short", "�_��");
	set("long",@LONG
�A�@��F�F�o�̡A�N�ݨ�F�F�䦳�@�a�ܤj�����ȴ̡A���G�N�O�b
�L�W��פ��W�D�I�⪺���ͫȴ̡A�A���G�i�H�ݨ�b���̦��\�\�h�h��
�ȫȦb�𮧡A�_��O�B�F�����_��A�n��h�O�B�F�����������s���A�A
�ϩ�ť��F�䪺�ȴ̦��@�ǤM�C�V���n�C
LONG
	);
	set("exits", ([
  "south" : __DIR__"boo-lin.c",
  "north" : __DIR__"bnorth1.c",
  "east" : __DIR__"hotel.c",
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
	replace_program(ROOM);
}
