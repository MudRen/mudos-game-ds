// jiunang.c  �j�s�n

inherit ITEM;
inherit F_WATER;

void create()
{
	set_name("�j�s�n", ({"wine skin","skin"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "�@�u�O��쪪�����j�s�n�A�̭��˺��F�����������s�C\n");
		set("unit", "�u");
		set("value", 500);
        set("heal_mp", 10);
		set("water_remaining", 5);
	}

}
