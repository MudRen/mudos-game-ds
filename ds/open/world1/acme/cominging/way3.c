inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�o�̤w�O���D�����ݡA�b�A�����e�O�@�Ӧ��G�O���̤�Ұ����j��
�A�j���W�e�ۨ�Ӷǩ_�H���A���G�Ψ��ר��Ϊ��A���L�n���������Ǥ�
��l�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yidoor",
  "south" : __DIR__"way2",
]));
	set("no_clean_up", 0);
        set("light",1);

	setup();
	replace_program(ROOM);
}
