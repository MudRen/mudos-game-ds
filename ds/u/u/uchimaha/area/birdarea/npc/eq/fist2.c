#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit FIST;

void create()
{
    set_name(HIR"�E����"NOR,({"nine-fox claw","claw"}) );
    set("long","�E�������l�A���ˤO�D�`�j�A�ǻ��u�n�t�W�o�����l�A
�s���|�Z�\\�����`�H�]�i�H�ܦ��^���C\n");
        set_weight(7000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
        set("limit_level",15);
        set("limit_str",25);
        set("value",50000);
        set("wield_msg",
         HIW "$N����M�W$n"HIW+"�A�n��$N�����g�X����⪺����A�O�H���Ѫ��h�F�G�B�C\n"
         NOR);
        }
        set("weapon_prop/dex", 4);
        set("weapon_prop/int", -2);
        set("weapon_prop/str", 2);
        set("weapon_prop/bar", 2);
        set("weapon_prop/wit", -1);
        set("weapon_prop/sou", -1);
        set("weapon_prop/parry", 10);
        init_fist(70);
        setup();
}
