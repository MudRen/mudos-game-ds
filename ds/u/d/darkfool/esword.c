#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIW"���C"HIB"�C�]�̨�"NOR, ({"evil sword","sword"}));
	set_weight(1000);
	if( clonep() )
	     set_default_object(__FILE__);
           else {
		set("unit", "��");
		set("long","�@��ݰ_�����ª����C�A�K�K�³ª��j��躡�F��ӼC���C�A�����ۼC�W\n"
		"���j��A��Mı�o���ǩ_�ΩǪ����r�n�����ͩR��ۤv�y�ʤF�_�ӡI�O�A\n"
		"���T���F�@�ӴHŸ�C\n");
		set("value", 8000);
		set("material", "steel");
		set("wield_msg", "$N�N$n��a�@�n��X�Ӵ��b��W�C\n");
		set("unwield_msg", "$N�N$n���F�_�ӡC\n");
	        	
	}
	init_sword(100);
	setup();
}