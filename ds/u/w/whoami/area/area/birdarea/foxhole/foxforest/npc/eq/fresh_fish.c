inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�A��", ({ "caller" }) );
        set_weight(240);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�����۶ø����A���A�j���~��Q��줣�[�E\n");
                set("unit", "��");
                set("value", 260);  
                set("food_remaining",2);
                set("heal_hp",130);   
                set("heal_ap",180);  
                set("heal_mp",140);  
        }
}

