inherit ROOM;

void create()
{
	set("short", "�}�]��");
	set("long", @LONG
�o�̪��Ŷ��j���O�H��Y�I���Z�L��ê�����a���B�W�Y�j�����a
��H���A²���i�H�B���@�Ӥp�������|�ҡC�����D�o�@�ӥ��j���a�U
�եެO���y�����C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"gcave11",
  "southeast" : __DIR__"gcave12",
  "south" : __DIR__"gcave10",
  "northeast" : __DIR__"gcave8",
]));

	setup();
	replace_program(ROOM);
}
