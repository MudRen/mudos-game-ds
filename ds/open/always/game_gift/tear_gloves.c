//�� /std/item/game_gift.c �гy by -Acme-

#include <armor.h>
#include <ansi.h>
inherit HANDS;

void create()
{
        set_name(HIC"�L"HIW"��"HIR"�\\"HIY"��"NOR , ({ "Magic-tear's gloves","gloves" }) );
	set_weight(2139);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O�y�v(Acme)�O�ɤd���U�W���W�j�ǻ������L�Ьu��
�ñN�U�~�������w�b�L�Ьu�����C�C�|�Q�E�ѡA�l�����
��ءA�ý�´�k�N��´���L�W���_�y�L�в\\���z�C");
		set("unit", "��");
		set("value",2535);
	}
	set("armor_prop/con", 1);
	set("armor_prop/int", 1);
	set("armor_prop/armor", 4);
	set("armor_prop/shield", 4);
	setup();
}
int query_autoload() { return 1; }
