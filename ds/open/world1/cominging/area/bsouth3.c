inherit ROOM;
void create()
{
	set("short", "�B�F���n�j��n");
	set("long",@LONG
�A�����b�B�F�����n�j��n�䪺���W�A�b�o�̤�_��n�����\�h�A
�]�S�����_��p���h�����a�A���L�o�̫o���@�a�W�D�I�⪺�v�޳��A�b
�����~�䦳�\�h���۶i�J�D�Ԫ��_�I�̡A�K�p�@�����s�@�멵�����
���ݡC
LONG
	);
	set("exits", ([
  "north" : __DIR__"bsouth2.c",
  "east"  : __DIR__"hippodrome.c",
  "south" : __DIR__"bsouth4.c",
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