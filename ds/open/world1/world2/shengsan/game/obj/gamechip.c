// gamechip.c			Shengsan@DS	1999.4.4
// �w�X

inherit MONEY;

void create()
{
	set_name("�w�X", ({ "gambling chip", "chip", "game_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "�o�O�b�C�ֳ��~��ϥΪ��N���C\n");
		set("unit", "��");
		set("base_value", 1);
		set("base_unit", "�T");
		set("base_weight", 1);
	}
	set_amount(1);
}
