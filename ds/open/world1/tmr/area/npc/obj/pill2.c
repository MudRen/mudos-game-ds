inherit ITEM;
inherit F_PILL;
void create()
{
	set_name("������", ({ "breath pill", "pill" }));
	set("long",@LONG
�������]�O�����ұ`�Ϊ��ĤY�A�D�n�O�Ψӫ�_�w���h����O�A��j
�ɤY�Φ��۷����C
LONG
);
	set_weight(455);
	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "��");
	}
	set("value", 300);
	set("heal",([ "mp":70, ]));
	setup();
}
