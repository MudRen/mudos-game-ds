inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�t�D��",({"smoke salmon","salmon"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�ȩ��u�G�H��§�g�v���o�N���@-�t�D���C\n");
                set("unit", "��");
                  set("value",200);
                set("heal_hp",25);
               set("food_remaining",3);
        }
     setup();
}


