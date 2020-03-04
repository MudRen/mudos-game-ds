// Room: /future/area/digging_road7.c

inherit ROOM;

void create()
{
	set("short", "�q�s�}�f");
	set("long", @LONG
�A�����b���ϱ��q�Ϫ��q�s�}�f�A�b�A������O�y���j���q�ϡA�b��
��B��n��B��_��U���T�Ӭ}�f�A���o�q���q�s�������T�ӱ��q�}�A��
�ɦ��q�u�i�i�X�X�A�h�B�۱ı����q���A�q�}�̤]���ɶǥX�}�}�K�B�ۼ�
�����n���A�ݱo�X���q�u�̷��O��O�u�@�C
LONG
	);
	set("world", "future");
	set("outdoors","desert");	
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
	  "southwest" : __DIR__"digging_road10",
	  "west" : __DIR__"digging_road9",
	  "northwest" : __DIR__"digging_road8",
	  "east" : __DIR__"digging_road6",	
           "south" : "/open/world3/kkeenn/secret-area/enter.c", // add by -Acme-
	]));

	setup();
	replace_program(ROOM);
}
