#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FIST;

void create()
{
    set_name(HIR"�E����"NOR,({"nine-fox-claw","claw"}) );
    set("long","�E�������l, ���ˤO�D�`�j, �ǻ��u�n�t�W�o�����l,
�s���|�Z�\�����`�H�]�i�H�ܦ��^���C\n");
        set_weight(7000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
        set("material", "leather");
        set("limit_lv",30);
        set("limit_skill",60);
        set("wield_msg",
         HIW "$N����M�W�@��$n"HIW+"�A�n��$N������X����⪺����A�O�H���Ѫ��h�F�G�B�C\n"
         NOR);
        set("limit_con",30);
        set("limit_dex",40);
        }
        set("weapon_prop/dex", 4);
        set("weapon_prop/int", -2);
        set("weapon_prop/bar",1);
        set("weapon_prop/wit", -1);
        set("weapon_prop/sou", -1);
        set("weapon_prop/parry", 10);
        init_fist(62);
        setup();
}
