inherit ROOM;

void create()
{
	set("short", "�}�]���e��");
	set("long", @LONG
�o�̬O�}�]�̪��e�����@�A�U�p���q�D���H�Pı���I���ΪA�A��
�O���������A�ר�O�a���ٻᬰ���Z�A�n�����H�`�`�b�o�̦樫�@��
�C�a�W�n�����ǩ_�Ǫ���v�����C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  		"southwest" : __DIR__"gcave1",
  		"north" : __DIR__"gcave5",
	]));

	setup();
	replace_program(ROOM);
}
