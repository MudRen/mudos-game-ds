#include <weapon.h>

inherit FIST;

void create()
{
	set_name("�T��",({"wolf fist","fist"}) );
	set("long",@long
�@�樂�򮱮v�`�t�����T���A���{��հ��˼W�[�F���֧����O�C
long
	);
      set_weight(1500);

	if(clonep() )
		set_default_object(__FILE__);
	else
	{
        set("value",1000);
	set("unit","��");
	set("wield_msg","$N���_�@��$n�����b��W�A���G�j�F���֡C\n");
        set("material","iron");
	init_fist(15);
	set("weapon_prop/armor",5);
	}
	setup();

}
