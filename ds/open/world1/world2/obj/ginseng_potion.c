inherit ITEM;
inherit F_WATER;
void create()
{
	function f;
	set_name("�H���Ĥ�", ({ "ginseng potion","potion" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
  �o���Ĥ��O�Ѿ����H�Ѻ�s�Ӧ��C��(drink) �F����i�H�j������
��ť�������~�q�ؤ��Īp�C
LONG);
		set("unit", "�~");
		set("material","water");
	}
	set("value", 620);    
	set("heal_mp",100);
	set("heal_ap",100);
	set("heal_hp",400);
	set("water_remaining", 1);
	setup();
}
