inherit ITEM;
void create()
{
	set_name("���F",({ "golden sand","sand" }));
	set_weight(1000);

	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","�@�رq������B���_�Ӫ�����A���G���F�汼�ٷQ���X����\\�ΡC\n");
		set("unit","��");
		set("value",100);
	}
	setup();
}