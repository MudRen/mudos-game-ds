/**
 *	Shadow's sword - ���
 *	�H�C���C���d���ק蠟.
 */
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIR"���"NOR, ({ "blood wave sword","sword" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {		
		set("unit", "�`");
		set("long",@LONG
    ���C�W���u����v�A�j�����q�������N�A�D�O�@�`�j��i�_
�}�ĥҦp�L�������@�_�C�C�C���C�ءA�C�T�観�j�N�ʤ�B�C�`
�B��H�j�fű�ۡu����v��r�C��C�@�ݡA�u���������ꪺ�S��
�C��W�����Ǭ��対�A�çe�i�������A���ѱo���H�g�ĳo�`�_�C
�T���m�@�ǧ@�I
LONG
		);
		set("needaward", 40);
		set("value", 1);
		set_weight(8000);
		set("material", "blacksteel");
		set("no_drop", 1);
		set("can_give", 1);
		
		set("wield_msg", HIR"$N�˳ƤW����A���������{�L�@�ٮ������I\n"NOR);
		set("unwield_msg", RED"$N���U�F����A�ť���ߪ�����]���M�h�h�I\n"NOR);
		
		set("weapon_prop/con", 2);
		set("weapon_prop/hit", 30);
		set("weapon_prop/bar", 2);
		set("weapon_prop/wit", -1);
		init_sword(60);
	}
	    
	setup();
}

int query_autoload() { return 1; }
