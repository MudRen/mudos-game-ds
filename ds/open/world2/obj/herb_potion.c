inherit ITEM;
inherit F_WATER;
void create()
{
	function f;
	set_name("�ʯ��ľ�", ({ "herb potion","potion" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
  �ثe�����W�̸g�٪��Ĥ��C��(drink) �F�i�H���ɨ���A�ĪG�����C
LONG);
		set("unit", "�~");
		set("material","water");
	}
	set("value", 50);    
	set("heal_hp",50);
	set("water_remaining", 1);
	setup();

}
