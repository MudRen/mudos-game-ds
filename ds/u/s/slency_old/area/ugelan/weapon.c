// Room: /u/s/slency/area/ugelan/weapon.c

inherit ROOM;

void create()
{
	set("short", "�Z����");
	set("long", @LONG
�o�̬O�����̥X�W���Z�����A�ҽ�M�C���������A�W�Q���լ���S
��Ať�����������K�v���O�Υ_�跥�H�a�a�ҹB�e�^�Ӫ���谵������
�A�[�W�W�s�������A��ű�M�C�O�ѤU�D�W���A���L�]�]������y�Q�F��
�A���n�i�^���D�W�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road2",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
