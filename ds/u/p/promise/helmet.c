#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIW"�զ⤧��"NOR, ({ "Showing love", "showing", "love" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","Aring�M��....:P \n");
                set("unit", "��");
                set("material", "unknown");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("no_sac",1);
                set("value",1);
        }
        //============�H�U���q�}��ϰ�ť�, �_�h�|�j�V��===============
        //==    �Y�}��ϰ�n�g���ذ���eq , ���w�n�]�� Only One EQ    ==
        set("armor_prop/id",  ({"(Snowelf) "}));
        set("armor_prop/short",({HIC"����"HIW"�T�@"NOR"(Snow elf)"NOR}));
        set("armor_prop/long", ({"�t����\ \n"}));
        //==============================================================
        set("armor_prop/armor", 120);
        setup();
}
int query_autoload() { return 1; }

