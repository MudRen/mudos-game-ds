#include <armor.h>
#include <ansi.h> 
inherit FINGER;

void create()
{
        set_name(HIC"五雷經籙之戒"NOR,({"five-thunder ring","ring"}) );
        set("long",@LONG
五雷是道教雷法常用之辭，說法不一，或指金、木、水、火、土五行
之雷；或指天雷、水雷、地雷、神雷、社雷；或曰風雷、火雷、雲雷、蠻
雷、電雷；或曰天雷、地雷、水雷、神雷、妖雷；又有雷大、雷二、雷三
、雷四、雷五之說。一般多以前列第一種為主，謂五行相生相剋，陰陽薄
動，震發為雷，故五行金、木、水、火、土皆能發雷，是謂五雷。五雷經
籙之戒，是召發調遣五雷的經籙文書上的印信。旁列連線五星點似是指五
雷，而與五星關係不大。
LONG
);
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("volume",3);
                set("unit","只");
                set("value", 15000);
        }
        set("armor_prop/armor", 5);
        set("armor_prop/bio",1);
        set("armor_prop/con", 1);
        set("armor_prop/dex", 1);
        set("armor_prop/sou",-1);
        setup();
}

