//�x�W�C���Ĥ@������ �ĤT�W judith ���~ -by tmr- 2000/5/20

#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("�w�w���n�֥�" ,({ "papa armor","armor"}) );
        set("long",@long
�x�W�C���Ĥ@������ �ĤT�W judith ���~
    �@���i�R���w�w���C
long
);
          set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��" );
                set("value",1000);
                set("valme",4);
                set("no_sac",1);
                set("armor_prop/armor", 10);
		set("wear_msg","�@���i�R���w�w���A�e��F�@���i���a�w�b$N�����W�C\n");
		set("remove_msg","�i�R���w�w�����_���l�^��$N���h���C\n");
        }
        setup();
}

int query_autoload() { return 1; }
