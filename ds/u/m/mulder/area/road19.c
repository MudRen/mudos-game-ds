// Room: /u/m/mulder/area/road19.c

inherit ROOM;

void create()
{
	set("short", "�©�");
	set("long", @LONG
   �o�N�O�s���o���̦��W�𪺦a��u�©��v�A�A�oı���ӷ|
���N�Q���쪺�a��A�u���o�ئ��ܦh���P���H�b���R��A�A�n�_
�a���h�ݬݦ�����n�Ϊ����~�i�R.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "leave" : __DIR__"road9.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
