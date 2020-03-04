//這種會暫時加屬性的丹，算是個特別品，只有另外寫了。
#include <ansi.h>
inherit ITEM;
void delay(object me);

void create()
{
        set_name(HIC"神奇藥丸"NOR,({"powerful pill","pill"}) );
        set("long","這是一粒稀有的藥物。\n");
        set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",100000);
                set("unit","粒");       
        }
        setup();
}

void init()
{
        add_action("do_eat","eat");
}

int do_eat(string arg)
{
        object env;
        string type,msg;

        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        if(! env = environment(this_object())) return 0;
        if(env !=this_player() && !this_object()->query("no_get")) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");
        if(this_object()->query("do_eat") )
                return notify_fail("你已含在嘴裡了。\n");

        message_vision("$N從懷裡拿出一顆泛著"HIR"紅光"NOR"的藥丸含在口中。\n",this_player() );
        tell_object(this_player(),HIW"你忽然覺得你的力量增強了不少！！\n"NOR);

        this_player()->add_temp("apply/str",10); //附加str
      this_player()->add_temp("apply/int",10);
      this_player()->add_temp("apply/dex",10);	    		    
      this_player()->add_temp("apply/con",10);	    
        this_object()->set("do_eat",1);
        this_object()->set("no_drop",1);
        this_object()->set("value",0);
        this_object()->set("no_sac",1);
        call_out("delay",300,this_player() );     //附加屬性維持時間

        return 1;
}

void delay(object me)
{
        tell_object(me,HIW"隨著你口中的神奇藥丸漸漸融化，你的力量慢慢地回復了。\n"NOR);
        me->add_temp("apply/str",-10);
      me->add_temp("apply/int",-10);
      me->add_temp("apply/dex",-10);
      me->add_temp("apply/con",-10);	
        destruct(this_object() );
}
