#include <weapon.h>

inherit BLADE;

void create()
{
set_name("�u�E��ʤM",({"watermelion blade","blade"}));
set("long","�o���ӬO�ΨӤ���ʪ��M�l,���O�Q�V�V���ӷ�F�����u��.\n");
set_weight(7800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",300);

set("material","iron");
set("limit_str",5);
set("limit_dex",5);
        }
set("wield_msg","$N�q�@�����Ȥ���X�@��W�Q��$n\n");
set("unwield_msg", "$N��U�⤤��$n, �γ��ȥ]�n���ð_�ӡC\n");
init_blade(15);       
set("combat_msg", ({    
"$N�⮳$w�A�@�nX�A�Q�A��$n���Y�A�F�L�h�A$n���Y�����y���`",
"$N�������դ����A���֩��s�P�١A�@�n���O���U�A�u���@�s�H�ĥX�ӡA����$n�N�O�@�y�å�",
"$N�j�|:�u�٨S�_���N�Q�b�o�̷m�a�L?�v�A��O$n�N�~�}�x�F�A�A�A�X��ӤJ�A��F$n�@�}",
"$N�A�X$n�Q�k�]���ɫ� �A�b$n�᭱�ɤF�@�M",
"$N�ΤM���$n����l�A���K�����䤣�����Ӫ��j����$n���Y�V�츣�}��",}) );
setup();
}
