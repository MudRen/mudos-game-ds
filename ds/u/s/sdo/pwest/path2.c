inherit ROOM;

void create()
{
	set("short", "�˪L");
	set("long", @LONG
�q�o�̶}�l�N�O�@�j�����˪L�F�A�Ӧ���O�@�j�����C�o�̪�
�������Q���Z�K�A�ӥB�D�`���j�A�ݰ_�Ӥ]�D�`�a�Ѫ��ˤl�C�b�o
�ӴX�g�Զê���@�j���W�A�ٯu�O���e���ݨ��C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  		"northeast" : __DIR__"path3",
  		"west" : __DIR__"path1",
	]));

	setup();
	replace_program(ROOM);
}
