inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("���U", ({ "water bag","bag" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�Ӥ��ֻs���U�l�A���Y�˪��i�Ѵ����M���C\n");
                set("unit", "�~");
                set("value", 20);       
                set("heal_mp",5);      
                 set("water_remaining", 5);
        }
}
