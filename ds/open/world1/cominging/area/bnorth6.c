inherit MOBROOM;
void create()
{
	set("short", "�_��");
	set("long",@LONG
�o�̬O�B�F�����_�󥽡A�@����������N�즹����F�A�b�_��O��
��������M�����A�b���������@�Ǥp�c�A���G�b�c��L�Ү��ⰵ���F��
�A�n��O���B�F���������A�ӥ_��h�O�����~���C
LONG
	);
	set("exits", ([
  "south" : __DIR__"bnorth5.c",
  "north" : __DIR__"bdoor2.c",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("chance",29);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	setup();
}