inherit ROOM;

void create()
{
	set("short", "�}�]��");
	set("long", @LONG
�}�]��o�S���������l�A�ݨӺ��Y�t���h�N�֭n��F�C���L�n��
�٦��@�Ӥp�p���Ŷ��A�Ӥ��n�N�O�q���̶ǥX�Ӫ��C�o�ް_�A���n�_
�ߡA�Q�n���ֹL�h�ݤ@�U�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 4 */
  		"northwest" : __DIR__"gcave11",
  		"north" : __DIR__"gcave10",
  		"northeast" : __DIR__"gcave12",
  		"south" : __DIR__"gcave14",
	]));

	setup();
	replace_program(ROOM);
}
