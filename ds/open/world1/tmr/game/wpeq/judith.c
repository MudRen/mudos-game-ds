//掌上遊戲第一屆比賽 第三名 judith 獎品 -by tmr- 2000/5/20

#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("趴趴熊軟皮甲" ,({ "papa armor","armor"}) );
        set("long",@long
掌上遊戲第一屆比賽 第三名 judith 獎品
    一隻可愛的趴趴熊。
long
);
          set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "件" );
                set("value",1000);
                set("valme",4);
                set("no_sac",1);
                set("armor_prop/armor", 10);
		set("wear_msg","一隻可愛的趴趴熊，牠轉了一圈懶散地趴在$N的身上。\n");
		set("remove_msg","可愛的趴趴熊捲起身子回到$N的懷中。\n");
        }
        setup();
}

int query_autoload() { return 1; }
