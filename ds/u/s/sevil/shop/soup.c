inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("�|����", ({ "soup" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�J����|�����|�����A�O�H���C�T�ءC\n");
                set("unit","�J");
                    set("value",180);
           set("heal_ap",20);
                set("water_remaining",3);
        }
     setup();
}
