// Room: /u/m/mulder/area/shop4.c

inherit ROOM;

void create()
{
	set("short", "�s���o�Ȧ� -");
	set("long", @LONG
�o�O�s���o�����̤j�Ȧ�A�A�i�H�b�o�ش��کΦs�ڡD����
�A�@�|��i��s���o�����ө���A�Ӥ@���j�ʪ��D�M�@�M�A����
�]�A�p�A�n�s�ڨ��N�n�֤F�A�]���i�঳�@�ǤH���b�������A
�A�����D
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road5",
]));
	set("no_clean_up", 0);
	set("objects",([
__DIR__"npc/security" : 2,

	]));

set("light",1);
	setup();
	replace_program(ROOM);
}
