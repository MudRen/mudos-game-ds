inherit ITEM;
inherit F_WATER;
void create()
{
	set_name("�N�M�l", ({ "burn blade wine","wine" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	      set("long","�o�ذs�Q�������@�P�A���O�߱��{�e�A��\n"
		"�O�u�����ҧx�v���H�O���|�h���ժ��C\n");
	      set("unit", "�~");
	      set("value", 150);       
	      set("heal_ap",10);
	      set("water_remaining", 5);
	}
	setup();
}
