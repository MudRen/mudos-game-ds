inherit MOBROOM;
void create()
{
	set("short", "�_��");
	set("long",@LONG
�o�̦��@�ɴ��e�j���ؿv���A�A�Q�j���N�O�B�F�������x���F�A��
�D�̪�x�����@���j���i���ˤl�A���G�O�����_�F���i���ˤl�A���L��
�֤S���R�F�U�ӡA�B�F�����x���O�����̰����ؿv���A�������T�h�Ӱ�
�A����N�O�x�����J�f�F�C
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth4.c",
  "north" : __DIR__"bnorth6.c",
  "west" : __DIR__"polity.c",
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
