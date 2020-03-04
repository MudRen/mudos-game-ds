// bottle.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�C��Ī", ({ "green calabash", "calabash" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�o�O�@�ӺѺ�⪺��Ī�M�C�̳z���C��Q���Q�H�߷R�C\n");
		set("unit", "��");
		set("value", 80);
		set("max_liquid", 60);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "�̬u��",
		"remaining": 60,
	]) );
}
