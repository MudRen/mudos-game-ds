#include <armor.h>
#include <ansi2.h>
inherit FINGER;
void create()
{
        set_name(HIW"雪人戒指"NOR, ({ "snowman ring","ring" }) );
        if( clonep() )
        	set_default_object(__FILE__);
        else 
        {
        	set("long",@LONG
這只戒指是２００１年的堆雪人活動的獎品，造型是一個小小的雪人
，樣子非常可愛，而且隱隱約約還會發著光亮。
					           by sdo@DS
LONG
	);
                set("unit", "只");
        	set_weight(600);
       		set("no_sell",1);
        }
        set("material","jade");
        set("armor_prop/armor", 15);
        set("armor_prop/con",2);
        set("armor_prop/int",1);
       	set("armor_prop/dex",1);
        setup();
}

int query_autoload() { return 1; }

void init()
{
        object me= this_player();
        string id;

        add_action("do_wear", "wear");

        if( !me ) return;
        id = me->query("id");
        if( id != "wait"
        &&  id != "roba"
        &&  id != "rex"
        &&  id != "waited"
        &&  id != "sdo"
        )
        {
                tell_object(me, HIW"突然之間，"+this_object()->name()+HIW"的光芒消失了。\n"NOR);
                this_object()->delete("armor_prop");
                this_object()->set("value", 0);
                this_object()->set("name","稻草人戒指");
                this_object()->start_light(0);
                this_object()->set_durable(0);
                return;
        }
        if( this_object()->query("name") == "稻草人戒指" ) this_object()->create();
        if( environment(this_object()) == me )
        {
                if( !this_object()->query_light() ) this_object()->start_light(1);
        }
}

int do_wear(string arg)
{
        object me;
        me = this_player();

        if( arg == "ring" || arg == "snowman ring" ) 
        {
                if( !this_object()->query_durable() )
                        return notify_fail("你並沒有資格穿著這件ＥＱ。\n");
        }
}