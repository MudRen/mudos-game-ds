// Room: /u/m/mulder/area/road8.c

inherit ROOM;

void create()
{
	set("short", "�s���o�� - �s���j��");
	set("long", @LONG
�o�O�@�������j�D�A�A�i�ݨ�P�򪺹Ҧ�|�H�ɰ_�ܤơA�A
ı�o�u�O�Q�����_�ڡD���A�S�Q�ڷ|���|�H�o�Ҧ��H�ɰ_�ܤƩO
?�Ʊ�U���b�o�ةw�U�@�ӥؼЫe�i�D
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
"south" : __DIR__"chatroom",
  "west" : __DIR__"road7",
  "east" : __DIR__"road9",
]));
	set("�s���o��", "- �s���o�j�D");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
