#include <ansi.h>
#include <weapon.h>  
inherit SWORD; 
void create()
{
        set_name(NOR+MAG"����"HIM"�K����"NOR, ({ "yin-yang eight umbrella" ,"umbrella" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",10);
                set("unit", "��"); 
                set("limit_str",60);
                set("limit_int",20);
                set("limit_dex",40);
                set("limit_con",40);
                set("limit_lv",40);
                set("armor_prop/int",3);
                set("armor_prop/wit",1);
                set("long", HIR"�Ǩ��Ǯ𪺤@��ʡA�W���K���F�ũG�A������o�O�`�ٳ̱o�N���@�⯫�L�C\n"NOR);
                set("value", 20000);
                set("wield_msg",HIR"$N���_����ʫ�A�����W�U���o�X�@�ѿ@�@������C\n"NOR);
                         
        }
        init_sword(70);
        setup();
}
void attack(object me,object victim)
{
        object ob;
        ob=this_object();
        ::attack();
        if(!me) return;
        if(!victim) return;
        if( random(10) < 6 && !me->is_busy()) return;
        message_vision(HIW"�q"NOR+MAG"����"HIM"�K����"HIW"�̴��o�X�@�ǳ\\��"HIY"����"HIW"�A��¶�b"NOR"$N"HIW"���W�A�O"NOR"$N"HIW" ��_�I����C\n"NOR,me,victim);
        tell_object(me,HIY "�A��_�F�I����C\n" NOR);
        me->receive_heal("hp",20);  
        victim->receive_damage("hp",20,me) ;
        return;
}

