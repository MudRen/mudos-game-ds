inherit ROOM;

void create()
{
	set("short", "�a�U�e�D��");
	set("long", @LONG
�A�ݵۦa�U�e�y�A�~���D�G�y��Ӥ��n�O�q�o�̵o�X�Ӫ����C�z
��F�ۧA���}��A�@�}�}���檺�e���ֳt���y�L�A�q�_�����᰸����
�|�Q��A���}�W�A���A�۵M�ӵM�����}�@�I�C�ݵ۪e���y�V�·t���t
�@�Y�A���A���@�د������Pı�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"gcave13",
	]));

	setup();
	replace_program(ROOM);
}
