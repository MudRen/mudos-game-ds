// teie-ling.c
inherit ITEM;

void create()
{
	set_name( "�����O", ({ "chongyang ling", "ling", "iron" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@���Ω�q�歫���c���Kű�O�P�C �Ѥ����u�Hñ�o�A�ܦU���^���J�c�[§�C\n");
		set("value", 100);
		set("material", "iron");
	}
	setup();
}

void init()
{
	call_out("dest", 1800);
}

void dest()
{
	destruct(this_object());
}
