inherit MOBROOM;
void create()
{
	set("short", "�B�F���n�j��_");
	set("long",@LONG
�o�̬O�B�F���n�䪺�n�j�󪺥_���A�b�o�̦��a�p�p�����㩱�A�b
���̭����ɦ��@�Ǳ����Ϊ̬O�s�f���n���]�X�ӡA�b�_��O�B�F���n�j
��򤤤ߪ��汵�B�A�ӦA���n�h�O�n��j�󪺤����A�n�j��O�B�F����
�̦��W���@����A�D�O�]���\�h���W���c�⩱���b�䤧�W�A�ӥB�B�F��
�x���]�b������C
LONG
	);
	set("exits", ([
  "north" : __DIR__"boo-lin3.c",
  "south" : __DIR__"bsouth1.c",
  "west" : __DIR__"eqshop.c",
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