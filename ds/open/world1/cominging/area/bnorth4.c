inherit MOBROOM;
void create()
{
	set("short", "�_��");
	set("long",@LONG
�o�̪��F�䦳�@�ƪ����Ʃ��A�w�g�j��A�L�k�Q�����a�B�A�o�̬O
�B�F�����̤j�q�c�����a��A���ܦh�����`�k�l���b���ʶR���ơA�n��
�����B���G���@�a�����ˤl�A�o�̪��a�W���\���F���u���\�b�M�Ӥ@��
�������C
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth3.c",
  "north" : __DIR__"bnorth5.c",
  "east" : __DIR__"mercery.c",
  "west" : __DIR__"r_spinner.c",
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
