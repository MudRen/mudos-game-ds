#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
set_name(HIC"�iSM�Ρj"HIW"���@"NOR,({"sm whip","whip"}));
set("long","�o�O�@��SM���@,�i�H�W�[�@�Ǳ���εh��.\n");
set_weight(7600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",1800);

set("material","iron");
set("limit_str",5);
set("limit_dex",6);
        }
set("wield_msg","$N�q�@�ָy�ڤ���X�@��������$n\n");
set("unwield_msg", "$N��U�⤤��$n, �i�b�y�ڮ���C\n");
init_whip(14); 
set("combat_msg", ({   
"$N�ⴤ$w�M�@��j�s:�u�s�ڤk��!!�s�ڤk��!!�v�M���ۻ��ۧ�$W�Ϩ��設�W",
"$N��$w��$n���I���u�u����!�v���@�n�@�F�L�h�M���O$N��$n��:�u�n�n~���٭n~�v�M",
"$N��$w��$n��������¶����򪺡M���M$n�ֲ������ݰ_�Ӧn���ܲn",
"$N����$w�M�@��j�s:�u�s�ڪ��W!!�s�ڪ��W!!�v�M�M��Χ�$n���饴���@�������Z",
"$N�X$n���L�ӮɥΡM$w��$n���Z�����M���K��F$n�X�}",
}) );
setup();
}

