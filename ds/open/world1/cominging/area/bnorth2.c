inherit MOBROOM;
void create()
{
	set("short", "�_��");
	set("long",@LONG
�o�̬O�@�ӫܥ��`����D�A��D�W���\�\�h�h���ӫȡA�o���񦳫�
�h�ɪ��Фl�A�j�������O�Υ��Y�[���Y�[�W�b�V���g�ҫئ����A�j����
�u���@�h�ӥ��k�A�t�@�Ǥ��O�Υ��Y���v�����h�O�ϥΤ@�رq�����W��
�H�ұa�Ӫ��K�s����A�H�H�������o�ܹ��Ǫ��C
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth1.c",
  "north" : __DIR__"bnorth3.c",
]));
	set("objects",([
  __DIR__"npc/traveller.c": 2,
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
