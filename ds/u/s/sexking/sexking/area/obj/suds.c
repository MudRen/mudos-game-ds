inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�إq",({"chicken leg","leg"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�饻���p�Y���@�A���D�٤����C\n");
                set("unit", "��");
                  set("value",70);
                set("heal_hp",20);
               set("food_remaining",2);
        }
     setup();
}


