inherit ROOM;

void create()
{
	set("short", "�L�۪k���q�D");
	set("long", @LONG
���b�������q�D�̡A��Ǫ��g�姹���S�����_�L�A�K�K�³ª��G
���F�������A������W���A�s�j�z�۪��a�O�W�A�C��@�p�q�Z���N
�X�{�F�C���p���ᬰ�@�ժ��ϮסA�ݰ_���I���O�@�ذ}�k�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"south" : __DIR__"cir12",
  		"north" : __DIR__"cir3",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
