// Room: /u/d/darkfool/area1/16.c

inherit ROOM;

void create()
{
	set("short", "�_��v�ϵ�D");
	set("long", @LONG
�o�̬O��_������v�ϡA��D������O�ѳt���κc������a�A�X
�ө~���êӴr�֦a�q�A���e�g�L�A�L�̪���W���۱��q�u��A�ݨӬO
�ǳƭn���q�|�h�W�u�A�n�䦳��������ت��t���ΡA�ݨӤ��O���q��
�q�u�H�a�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"17",
  "west" : __DIR__"14",
]));

	setup();
	replace_program(ROOM);
}
