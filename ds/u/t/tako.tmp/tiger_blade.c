#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
set_name( HIY "��z" HIW"���M"  NOR ,({"tiger blade","blade"}));
set("long","�o�O�@��� �E�� �˦ۥ��y���M,�ݭn�����C�C�|�Q�E�H����
            �A�Ѥ@���Ѫ�ܤU,���ݦѪ������K��,�L�ɩH����,�A�N����
            ��թ�X,��G����,�H���Ӱ�,�ܦ��@�Ⲥ�e���z�����M,�¤O
            �L�a,�Y������n,���D�� ��z �϶ݪ��R�B�C\n");
set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",2000)
;
set("volume",2);
}
set("limit_str",30);
set("limit_dex",32);
set("limit_int",23);
set("wield_msg",
"$N�q�I���X�@��$n���b�⤤,�u��$n�o�X���⪺���~,�R���۵L�������� �C\n");
set("unequip_msg", "$N��U�⤤��$n, �N$n���J�I�᪺�M�T��,���𺥺������C\n");
set("combat_msg", ({
   "$N�@���u���ѡv�A�M�y�o�X�����F��,  �W�A$n���ӡA�U��$n�B������ "  ,
   "$N���}�@ģ�A����ģ�_�A�ѤW���ĦӤU,�����e�զ⪺�����A �@���u���a�v\n
  �A��$n���y�ڱ٥h",
   "$N�ਭ�ߦa�A���⼵���A����ӤW$N�q$n�I��«�X�A�@���u���ѷ��a�v,$N\n
    ���W�o�X�j�j���Ӫ��Q��W�A�U��,��ä�������$n�������W�U�ӥh\n   
    ,$n�ϩ��ݨ���r�����~",
   "$N�_���B��,��⤤��z��$n����V��h,�@�� �u�����v,��z�ѥ��۱٦ܥk,��$n
    �����}�ӥh,$n�s���@�n",
   "$N�i�}�L���$n�H���@�n,�@���u�]���v���p�r�ꪺ�q�n,�_�����^�n��𤣮�\n
    �����U�⪺�M,��$n�����զӥh",
   "$N��M�@��,�@�� �u�g��v,�����Ө�����$n��h,$n�������,�Q$N����b�a�W,\n
     $N�ਭ��ģ,���W,�@�� �u�p�١v,$N�Ѫůe�U,����z���k�ͤ�",
   "$N���z�ϦV�ϥ�,�ର�M�`�ޤ�,�@�� �u�����v,$N�ΤO�����z��$n���W\n
     ���h,$n���P��_�F�@�D����,��$n���F$N������,$N���W�@���u���ѡv,�M�y\n
     �o�X�����F��,  �W�A$n���ӡA�U��$n�B������ "  ,
     "$N�_���B��,��⤤��z��$n����V��h,�@�� �u�����v,��z�ѥ��۱٦ܥk,��$n
    �����}�ӥh,$n�s���@�n���Q$n�{�F�L�h,$N���ۤU��,�@�� �u�p�١v,$N�Ѫůe\n
     �U,����z���k�ͤ�",
     "$N���z�ϦV�ϥ�,�ର�M�`�ޤ�,�@�� �u�����v,$N�ΤO�����z��$n���W\n
     ���h,$n���P��_�F�@�D����,��$n���F$N������,$N���ۤ@���u�]���v���p\n
     �r�ꪺ�q�n,�_�����^�n��𤣮������U�⪺�M,��$n�����զӥh",
}) );
init_blade(65);
setup();
}


