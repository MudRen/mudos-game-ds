inherit ROOM;

void create()
{
	set("short", "�p�٥~");
	set("long", @LONG
�o�̬O�s���p�٥~�����Y�W�A���Y�W���@�Ǭִ��A�۱�ﭱ�p�ٲ�
��t�I�A�q�~�ݸ̭����G���ǹs�áA���ӾA�X�ɱJ���ˤl�A�p�٬O�ѥ�
�Y�ҿv���A�~��ݰ_�Ӥ]�����઺�ˤl�C
LONG
	);
	set("exits", ([
  "west" : __DIR__"flurry22.c",
  "eastdown" : __DIR__"flurry18.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
