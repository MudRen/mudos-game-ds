#include <ansi.h>
#include <weapon.h>
inherit HAMMER;
void create()
{
set_name(HIC "�W�७����" NOR,({"flat-buttomed pot","pot"}));
set("long","�o�O�@�⦳�]�O��������A�@�ΦӥB���S�����A�����F��t�׭n�֡A�O�q�n�j\n");
set_weight(18000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",11000);
set("material","iron");
        }  
set("wield_msg","$N�q�I���X�@��$n���b�⤤,�ǳƪ�����n��C\n"); 
set("unequip_msg", "$N��U�⤤��$n, �N$n��b�I��C\n");
set("limit_str",15);
set("limit_dex",15);
set("combat_msg", ({
"$N���_������}����~���@�n����$n���Y�W�A���G$n�Q�������_���P",
"$N�X$n�ݧA�o��n�Ϊ���������̦��o�檺�ɫ�A�N���������V$n������",
"$N�b�{�����M���_���ӡA���թ�$n���W�@��A�y��$n���W���S��",
}) );
init_hammer(38);
        setup();
}



