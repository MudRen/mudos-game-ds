// Room: /u/m/mulder/area/road1.c

inherit ROOM;

void create()
{
	set("short", "�s���o��-�ȩ��j��");
	set("long", @LONG
�A�q�ȩ����X�ӡA�ݥس\�h����ު��]�ơD�O�A�ؤ��v���a
�N�A�����u�ಾ�b�o�@��S�@�󪺰���޳]�ƤW�D�O�A�t�I����
�h�q�O�W�W�A���n��Ө��u�O�v���D�V�_���i�H��s�����ߡD
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "inn" : __DIR__"inn",
  "north" : __DIR__"road2",
]));
	set("no_clean_up", 0);
set("light",1);

	setup();
	replace_program(ROOM);
}
