#include <ansi.h>
#include <armor.h>

inherit PANTS;

void create()
{
        set_name(HIM"�m"HIR"�O"HIY"�F"HIC"�s"NOR, ({ "rainbow salon", "salon" }) );
        set("long", @long
�@���e���C�m���O�����A�e�u��o�ӿ�Ĳ�P���X�ƶ��A���R���~
���U���G���õۤ@�ѯ������O�q�C

Game Gift of [2005 Summer] By Alickyuen@The.Dream.Of.Seven
long);
        set_weight(15000);
        set("value", 777);
        set("armor_prop", ([
                "bar" : 1,
                "shield" : 10,
                "armor" : 10,
        ]));
        set("armor_type", TYPE_PANTS);
        setup();
}

int query_autoload() { return 1; }

void init()
{
        if( environment(this_object()) == this_player() )
                if( !this_object()->query_light() ) this_object()->start_light(1);
}
