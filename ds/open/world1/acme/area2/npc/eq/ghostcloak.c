#include <armor.h>
inherit F_UNIQUE;
inherit SURCOAT;
void create()
{
        set_name("�ߤ��Ѥ�" ,({ "sky cloak","cloak" }) );
        set("long","�o��潴���G���Q�S���k�O�[���L�A���M���R���O\n"
                   "�o���`���㨾�m�O�P�@�ΫסC\n");
        set_weight(5000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "leather");
        set("unit", "��" );
		set("volume",4);
        set("value",8000);
        set("limit_lv",20);
	set("replica_ob",__DIR__"cloak");
        }
        set("armor_prop/armor",18);
        set("armor_prop/str",2);
        set("armor_prop/dodge",15);
        setup();
}
