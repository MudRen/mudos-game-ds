#include <weapon.h>
#include <ansi.h>
inherit WHIP;
void create()
{
        set_name(HIW"�D���M"NOR, ({ "snake-bone blade","blade" }) );
        set_weight(7400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��"); 
                set("long", "�@��¥ժ��Q�b�A�����D�쩳�O�Τ��򰵦����E���P�|���M���A\n"
                            "��n��Ψӧ������誺�ĤH�E\n");
                set("material", "gold");
                set("value",17000);
                set("limit_str",47); 
                set("limit_level",30);
        }
    set("weapon_prop/str",2);
    set("weapon_prop/dex",2); 
    set("weapon_prop/bar",1);
    set("weapon_prop/wit",-1);
    init_whip(69);
    setup();
}

