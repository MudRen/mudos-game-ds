#include <weapon.h>

//DEFAULT_WEAPON_LIMB "�k��"
//TWO_HANDED	1
//SECONDARY	2
//EDGED		4
//POINTED	8
//LONG		16

//AXE			"/std/weapon/axe"
//BLADE			"/std/weapon/blade"
//DAGGER		"/std/weapon/dagger"
//FORK			"/std/weapon/fork"
//HAMMER 		"/std/weapon/hammer"
//SWORD			"/std/weapon/sword"
//STAFF			"/std/weapon/staff"
//THROWING		"/std/weapon/throwing"
//WHIP			"/std/weapon/whip"

//F_AXE			"/std/weapon/_axe"
//F_BLADE		"/std/weapon/_blade"
//F_DAGGER		"/std/weapon/_dagger"
//F_FORK		"/std/weapon/_fork"
//F_HAMMER 		"/std/weapon/_hammer"
//F_SWORD		"/std/weapon/_sword"
//F_STAFF		"/std/weapon/_staff"
//F_WHIP		"/std/weapon/_whip"

inherit BLADE;

void create()
{
set_name("�}�s�M",({"kaisan blade","blade"}));
set("long","�o�O�@����Y���K�s�¦���M,���o�ؤM���H�q�`���O����n�H.\n");
set_weight(7600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",290);

set("material","iron");
//
// ����i�H�O 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
set("limit_str",5);
set("limit_dex",6);
        }
set("wield_msg","$N�q�@�����Ȥ���X�@��W�Q��$n\n");
set("unwield_msg", "$N��U�⤤��$n, �γ��ȥ]�n���ð_�ӡC\n");
//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	�R���v
//  weapon_prop/parry	�۬[�v
//  
init_blade(14); 	// �ˮ`�O=set("weapon_prop/damage", 14);
set("combat_msg", ({    //�����T�� $N�O�ۤv $n�O��� $l �O�����𳡦� $w�O�Z���W��
"$N�ⴤ$w�M���S�����M�r�a���$n��$l���F�L�h",
"$N��$w��$n��$l�����a�@Ѷ",
"$N��$w��$n��$l��h",
}) );
setup();
}
