// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�ڬ��J�s��");
	set("long", @LONG
�o�̬O�������ߪ��@�y�j���s���A���������@�y�Q�����A�����֤H
�򧤦b�����ǲ�ť�۵��Y���H�����֪�t�A����ǨӰ}�}���@�ح��O�H
�o�K�A�s���_�䦳�@�y���x�A�C�{����`�y�A�c�ʼ֮v���|�Ӧ���t, 
�o�O�d�z������R�@�~���������{�A�~���惡���ʤ]���Q�����P�ѻP
�A�Ǧ��]�������ֶQ�ڻP�������j�ҡA���n�O�@���ȩ��A���_�h�q����
�c�C
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road5",
  "south" : __DIR__"inn",
]));
	set("objects", ([ /* sizeof() == 1 */
	__DIR__"npc/obj/pot" : 1,
]));

 	set("outdoors", "land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}