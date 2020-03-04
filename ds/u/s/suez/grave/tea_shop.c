// Room: /u/s/suez/grave/tea_shop.c

inherit ROOM;

void create()
{
	set("short", "���v");
	set("long", @LONG
�o�O�@���έT��f�_��²��p���סA���׮Ǫ��_��K���Z�K�A�ӸH��
�����q�𸭶������b�|�P�a�W�A���@�j�A�N���x���@�a�H�[���@��A�b�n
�����w�����u�U�A�A�����F���G�S��M�F�\�h�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"path_10",
]));
	set("valid_startroom", "1");
	set("no_clean_up", 0);
        set("light",1);
        set("no_fight",1);
        set("no_kill",1);

	setup();
	replace_program(ROOM);
}
