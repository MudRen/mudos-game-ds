#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit DAGGER;

void create()
{
        set_name(MAG"�Q���F��"NOR,({"ten_dagger","dagger"}) );
        set("long","�@�⵵�⪺�P���A�Ϊ����O�@���D�A�P�W�������������ݨ�@�h����C\n");
        set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
              set("limit_level",12);
              set("material", "blacksteel");
        }
        set("wield_msg","$N�����F"MAG"�Q���F��"NOR"�A��W����������{�C\n");
        init_dagger(40);
        set("replica_ob", __DIR__"dagger.c");
        set("weapon_prop/dex", 3);
        set("weapon_prop/int", 4);
        setup();        
}