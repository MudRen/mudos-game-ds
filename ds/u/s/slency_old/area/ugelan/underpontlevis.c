// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�p�g�C");
	set("long",@LONG
�o�̬O�Q���U�������@�B�p�g�C�A��n�i�Ѥ@�ǤH���ߡA�A���Ǫ�
�g�����G���ǩ_�ǡA���@�����������Φb�d�g�᭱�A��Ǧ��@����÷�A
���ӥi�H�ɦ����^�Q���W�C
LONG
);
	set("item_desc" , ([ /* sizeof() == 2 */
	"�g��" : "�@�ӧG���d�F���g��A�g��ᦳ�@���K���C\n" ,
	"�K��" : "�@�ӥ��ת��K���A�����G�O��۪��C\n" ,
	]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
}
void init()
{
	add_action("do_climb","climb");
}
int do_climb(string arg)
{
	if(arg != "��÷") return 0;
	write("�A����÷�A�}�ΤO�@���D�W�F�Q���C\n\n");
	this_player()->move(__DIR__"pontlevis");
	return 1;
}
