// Modify with AreaMaker1.0
// Room28.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b�@���H�ϵ}�֪���L�̡C����M�n�䳣����צ�F�A��
�h���A�F�_���Ӥ@�}�}���j���A�g���I�I���j�ۡA�ϩ���Ӿ�L��
�b�n�̤@��C
LONG
	);
	set("exits", ([
		"north": __DIR__"room18",
		"east": __DIR__"room29",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

