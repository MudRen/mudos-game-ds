//u/c/chiaa/obj/eq/wolf_boots.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;
void create()
{
    set_name(YEL"�T"HBK"�u"NOR,({"wolf boots","boots"}) );
    set("long", "��W���N���b�j���W���T�@�˱ӱ��C\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(200);
                set("unit", "��");
                set("value",300);
                set("material","fur");
                set("armor_prop/armor",10);
                set("armor_prop/dodge",10);
                  }
      set("weapon_prop/dodge",15);        //�[ enable �ޯ�5
        setup();
}
