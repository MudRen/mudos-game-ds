#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( YEL "����" NOR , ({ "dog" }) );
       set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@���ݰ_�۷��q���g���M���q�j�����Q�Ӥ祪�k�C\n");
                set("value", 1000);
                set("material", "steel");
set("wield_msg", "$N��_$n����L�A�uť��$n�R�q���G�s�G�u�ӡ�ӡ��v\n");
                set("unwield_msg", "$N�N�⤤��$n��b�a�W�C\n");
        }
    init_sword(5000);
set("combat_msg",({
"$N��_$w����}�A��$n��$l�����h�A�@��" HIB "�u�ƪ��o�¡v" NOR "��$n��$l�g�r�C\n",
"$N��_$w���Y,�uť��$w�R�ת��G�s�A�ϥX�@��" HIY "�u���������v" NOR "�A\n"+
     "���۲��e��" HIY "����G��" NOR "��$n��$l�Q�h�C\n",
"$N���$w�j�F�j�f��A�ϥX�@��" HIG "�u���r�f�}���v" NOR "�u��$w�ĦV$n��$l�r�h�C\n",
}) ); 
        setup();
}
