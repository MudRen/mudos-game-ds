inherit MOBROOM;
void create()
{
	set("short", "���Y");
	set("long", @LONG
�o�̬O���Y�����Y�A�b�o�����Y���@�Ӥp�}�A�j���O���ߪ����X�J
���a��A���Y�����Y�W������}�l�����A�n���[�~���פ@��A�j���O�]��
�e�������ѳ��~�C�b�~�A���ɱ`�k�ӡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"flurry30.c",
]));
	set("no_clean_up", 0);
	set("chance",50);
	set("mob_amount",3);
	set("mob_object",({
  __DIR__"npc/dog",
  __DIR__"npc/cat",
}));
	set("light",1);
	setup();
}
