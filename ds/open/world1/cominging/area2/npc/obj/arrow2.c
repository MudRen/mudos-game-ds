// arrow �b: 2, NPC �νb
inherit ITEM;

void create()
{

	set_name("�K�b",({"iron arrow","arrow"}));
	set_weight(1250);
        if( clonep() )
        	set_default_object(__FILE__);
        else
        {
        	set("value", 10);
        	set("unit", "��");
        	set("long","�@���䳣���K�Ұ������@��b, �W���٦���ۨǦr, �ݳo�����q, ���ˤO���w���p�C\n");
        }
	set("arrow/damage", 20);         //���ˤO
	setup();
}