inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("���s���L",({"chicken leg","leg"}));
        set_weight(90);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�H���s�g���һs�A�֦������@�����һs�����D�C\n");
                set("unit", "��");
                set("value",70);
                set("heal_hp",25);
               set("food_remaining",5);
        }
     setup();
}

