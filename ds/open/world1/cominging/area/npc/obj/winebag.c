inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("�s�U", ({ "wine bag","bag" }) );
        set_weight(1180);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�Ӥ��ֻs���U�l�A���Y�˪��i�K�H���s���C\n");
                set("unit", "�U");
                set("value", 100);
		set("volume",2);
                set("heal_mp",10);
                set("water_remaining", 5);
        }
	setup();
}
