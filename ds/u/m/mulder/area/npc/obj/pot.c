inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("�Q����", ({ "pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("no_get",1);
		set("no_sac",1);
                set("long", "�@�ӼQ�����A�m��b�a�W�A���L�����H���ΡC\n");
set("unit","�y");
                set("value", 20);
                set("heal_hp",100);
                set("eat_func",5); //����5�H���i�H�L���ϥ�.
                set("water_remaining", 100);
        }
}

