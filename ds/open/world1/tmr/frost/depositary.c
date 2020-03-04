// Room: /open/world1/tmr/frost/depositary.c

inherit ROOM;

void create()
{
	set("short", "�øg��");
	set("long", @LONG
�h�ƹD�Юc�[���ؿv���ǲΪ��쵲�c�ؿv�A�Y�H��[�����F�A�����
�j��A�Υ˻\�γ��A������j���ȧ@�����~���j���ΡA���t�γ����q�C��
�øg�իh�O�ݩ�o���ؿv�A�Ӱ��C�h�A�îѸU���A���[�����D�n�ؿv���@
�A���`�O����~�H���N�i�X�C
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/taoist2" : 2,
  __DIR__"npc/hong" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"depositary2f",
  "west" : __DIR__"court2",
]));
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
