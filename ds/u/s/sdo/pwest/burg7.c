inherit ROOM;

void create()
{
	set("short", "�g���˪L���|");
	set("long", @LONG
�q�o�̶}�l�N�O�g���˪L���d��F�C�۸���U�ئM�I�����ɡA�g
���˪L�O�̷ũM�����ɡA�]���i�J�g���˪L���H��������w���X�ӡA
�u�O�ثe����S��ť������H��V�L�˪L�A��F�t�@��C���L�ھګ�
�B�����������A�t�@�����ӴN�O�y�����סz�A�]���L�̴��g�M�ѧ�
���׬��X�Ӫ��N��ñ�q�L���褬���z�Z�����w�C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  		"north" : __DIR__"burg8",
  		"west" : __DIR__"burg6",
	]));

	setup();
	replace_program(ROOM);
}
