#include <ansi.h>
#include <weapon.h>
inherit SWORD; 
inherit F_UNIQUE;
void create()
{
        set_name(HIC"�u�@��"HIW"��"HIR"�C"NOR, ({ "cover-sword", "sword" }));
        set("long", "�u�@�̤��F���t�C�A�露���������S�O���ĪG�C\n");
        set_weight(8000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("volume",5);
                set("material", "crimsonsteel");
                set("limit_skill",90);
                set("limit_str",30);
                      set("value",12000);
                set("limit_lv",40);
               }
        set("weapon_prop/armor",20); 
        set("weapon/prop/dodge",10);       
        set("wield_msg",HIC"��$N��X$n�����@�b���A�@�������j�j�F�𥿥R����$n�|�P�C\n");

        init_sword(70);
        setup();
}

