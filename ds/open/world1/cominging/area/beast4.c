inherit MOBROOM;
void create()
{
	set("short", "�B�F���F��p��");
	set("long",@LONG
�A���b�B�F���F�䪺�j��Ǫ��@���p���W�A�o����o�����٭n�w
�R�o�h�F�A�F��O�B�F�����j���A�Ӧ���h�O�������s���e�i�A�o�̦�
�@�ǨǪ��ؿv���A���o������򰪡A�b�����񦳤@�ǵ��H��K���T�Z��
�������ΰϡC
LONG
	);
	set("exits", ([
  "west" : __DIR__"beast3.c",
  "east" : __DIR__"beast5.c",
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