//u/c/chiaa/obj/eq/ten down_boots.c

#include <armor.h>
#include <ansi.h>
inherit BOOTS;
                        
void create()
{
    set_name(HIB"��"MAG"��"HIG"��"NOR,({"ten down boots","boots"}) );
    set("long", "�H�Y�ا���s��.��W����N���p�b�Ѫů�樫�̼˪����Z�C\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(150);
                set("unit", "��");
                set("value",1000);
                set("material","fur");
                set("armor_prop/armor",20);
                set("armor_prop/dodge",15);
                  }
      set("weapon_prop/dodge",15);        //�[ enable �ޯ�15
        setup();
}

