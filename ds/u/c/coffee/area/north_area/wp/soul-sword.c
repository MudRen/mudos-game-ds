#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIC"��"HIY"��"HIR"�]�C"NOR, ({ "soul sword","sword" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�o�O�@�����æb�v����餺���]�C�C������a�����A�A�������ˡC\n");
                set("volume",10);
                set("value", 20000);
                set("material","iron");
  }
                set("limit_lv",40);
                set("limit_skill", 80);
                set("weapon_prop/str",1);
                set("weapon_prop/con",3);
                set("weapon_prop/int",3);
                set("weapon_prop/wit",1);
                set("weapon_prop/hit",70); 
        set("wield_msg", "$N����$n�ɡA���G��Pı�즳�@�ѱj�j���O�q���C�Cı���C\n");
        set("unwield_msg", "$N��U�o��C�ɡA���ѱj�j���O�q�]�C�C�������C\n");
        init_sword(70);
        setup();
}

