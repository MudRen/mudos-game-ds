inherit ITEM;
void create()
{
	set_name("���s��", ({ "red-dragon flower", "flower" }));
	set("long", "���s��O�@�إi�H�s�����s�󪺪�ءC\n");
	set("weight", 300);
	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1);
	}
	setup();
}