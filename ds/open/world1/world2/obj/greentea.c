inherit ITEM;
inherit F_WATER;
void create()
{
	function f;
	set_name("���", ({ "green tea","tea" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
  �@���Τ@���q�Ͳ����³���C��(drink) �F�i�H���������ӥB�`
�ܺ���禳�������ĪG�C
LONG);
		set("unit", "�~");
		set("material","water");
	}
	set("value", 50);    
	set("heal_mp",25);
	set("water_remaining", 1);
	setup();

}
