// Room: /open/world1/tmr/dragoncity/house4n.c

inherit ROOM;

void create()
{
	set("short", "�֫ө��Ъ׫�");
	set("long", @LONG
�o�̴N�O�F�򪺪׫ǡC�Τl�̪����]��²��C�������䦳�@�i�n�ɡC
�ɤW���Q�ȳQ�|�o�������C���Y���諸�a���\�ۤ@�i�ާ��x�C��W�\��
�@�ӥ��G������A������䪺��~�̡A���@���ʦX��A���b���o�X�H�H��
�խ��C�����ۨ�i��ȡA�����O�@���L�A�W���\�ۤ@�֤s����C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"house4",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
