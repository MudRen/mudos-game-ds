#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIM"��"HIG"�i"HIW"�C" NOR, ({ "sky rainbow sword","sword" }) );
        set_weight(10000);
        if( clonep() )
                 set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("material","crimsonsteel");
                set("limit_str",40);
                set("limit_con",50);
                set("limit_int",20);
                set("limit_dex",30);
                set("long",
            "���C���C�m�⪬�A������O���b�ܤU�C\n");
                set("wield_msg", HIY"$N���_�ѭi�C��A�K��{�F�C�m������¶�b$N���ǡC\n"NOR);
                set("unwield_msg", HIW"$N��U�F�ѭi�C�A�K�֤F�C�m�G���C\n");
        set("value",10000);
        }
        set("weapon_prop/con",2);
        init_sword(69);
        setup();
}
void attack(object me,object victim)
{
        int damage,str,con,random1;
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(200)>150)
        {
        str = me->query("str")-random(22);
        con = me->query("con")-random(20);
        random1 = 1+random(2);
        damage = random1*(str+con)/5;
        victim->receive_damage("hp", damage, me );
        message_vision(HIM"��"HIG"�i"HIW"�C"HIM"�o�X�C�m�����A�C����~���ĦV$N"HIR"(-"+damage+")\n"NOR      
                ,victim);
        return;
        } 
        }

