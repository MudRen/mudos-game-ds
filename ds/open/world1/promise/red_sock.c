#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name(HIM"�t��"HIW"�w�w"HIR"��"NOR ,({ "xmas popo sock","sock" }) );
      set("long", @LONG
2003�~�t�ϸ`����EQ�C
LONG
);
           set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��" );
                //set("value",100000);
                set("valme",1);
                set("no_sac",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_auc",1);
                set("armor_prop/armor", 3);
                set("armor_prop/int",1);
                set("armor_prop/con",1); 
                set("armor_prop/str",1);
                set("armor_prop/dex",1);    
                set("wear_msg",HIR"$N��W�F�@��$n"HIR"��A�K��j�a��"HIM"�ۢ�����B�@"HIW"�Ѣ������������"HIR"���\n"NOR);
                set("unequip_msg",HIY"$N"HIY"��U�F$n"HIY"��A�Pı�S�o��"HIR"�t�Ϯ�"HIY"�I�I\n"NOR);  
  }

        setup();
}


int query_autoload() { return 1; }

