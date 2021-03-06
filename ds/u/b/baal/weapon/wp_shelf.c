#include <ansi.h>
inherit ITEM;
//int do_put(object me,string arg);
int do_xput(object me, object obj, object dest, int func);
void create()
{
    set_name(HIG"武器陳列架"NOR,({"weapon shelf","shelf"}));
        set("unit", "個");
        set("long",@LONG

  一個用來放置保存眾多武器的鐵架。你可以把珍貴的武器放在架
  上保存或是從架子中拿出你所喜愛的武器。

  放東西: put [東西] in weapon shelf
  拿東西: get [東西] from weapon shelf

LONG
);
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        set_max_encumbrance(999999);
        set_max_capacity(10000);
        setup();
}

void init()
{
        add_action("do_put", "put");
}

int do_put(string arg)
{
        string target, item;

        object me, obj, dest, *inv, obj2;
        int i, amount,active=0;
	me = this_player();

        if(!arg) return notify_fail("你要將什麼東西放進哪裡﹖\n");

        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("你要放什麼東西﹖\n");
	if( target == "shelf" || target == "equip shelf" || target == "weapon shelf" || target ==
	    "item shelf" || target == "shelf 1" || target == "shelf 2" || target == "shelf 3" )
		active = 1;
        dest = present(target, me);
        if( !dest || living(dest) ) dest = present(target, environment(me));
        if( !dest || living(dest) ) return notify_fail("這裡沒有這樣東西。\n");
        if( dest->is_box() )
        {
                if(!dest->can_access_box()) return notify_fail("你必須先打開"+dest->name()+"才能放東西進去。\n");

        }
        if(sscanf(item, "%d %s", amount, item)==2)
        {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("你身上沒有這樣東西。\n");
                if( obj==dest ) return notify_fail("來源和目的不能是相同的東西!\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分開。\n");
                if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"並不是一個容器。\n");
                if( obj->query_max_encumbrance() && !obj->query("no_get"))
                        return notify_fail( "容器不能放到容器裡。\n");
                if( obj->query("no_drop") )
                        return notify_fail( obj->name() + "不能被丟棄。\n");
                if( amount < 1 )
                        return notify_fail("東西的數量至少是一個。\n");
                if( amount > obj->query_amount() )
                        return notify_fail("你沒有那麼多的" + obj->name() + "。\n");
                else if( amount == (int)obj->query_amount() )
                        return do_xput(me, obj, dest, active);
                else {
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        if(!obj2->can_move(dest))
                        {
                                destruct(obj2);
                                return notify_fail("你沒有辦法把"+obj->query("name")+"放進"+dest->query("name")+"裡。\n");
                        }
                        obj->set_amount( (int)obj->query_amount() - amount );
                        return do_xput(me, obj2, dest, active);
                }
        }

        if(item=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if( inv[i] != dest ) do_xput(me, inv[i], dest, active);
                write("Ok.\n");
                return 1;
        }

        if(!objectp(obj = present(item, me)))
                return notify_fail("你身上沒有這樣東西。\n");
        return do_xput(me, obj, dest, active);
}

int do_xput(object me, object obj, object dest, int func)
{
        mixed no_put;
        if( obj==dest ) return notify_fail("來源和目的不能是相同的東西!\n");
	if( obj->query("equipped") ) return notify_fail( obj->name() + "正被你裝備著, 不能放到容器裡。\n");
        if( dest->query_max_encumbrance() < 1) return notify_fail(dest->query("name")+"並不是一個�
e器。\n");
        if( obj->query_max_encumbrance()  && !obj->query("no_get"))
                        return notify_fail( "容器不能放到容器裡。\n");
  if( obj->query("no_put")) return notify_fail("這東西不能放到容器裡。\n");  // add by wilfred
        if( obj->query("no_drop") )
                        return notify_fail( obj->name() + "不能被丟棄。\n");
        if( no_put = obj->query("no_drop"))
        {
                if(stringp(no_put)) return notify_fail( no_put+"\n");
                return notify_fail( "你無法把"+obj->name()+"放進那裡。\n");
        }
        if( obj->query_temp("riden") ) return notify_fail("你正在騎著耶!\n");
        if(!obj->can_move(dest)) return notify_fail("你沒有辦法把"+obj->query("name")+"放進"+dest->query("name")+"裡。\n");
	if( obj->query("secured") ) return notify_fail("你無法將設定為保存狀態的物品放進容器中.\n");
	if( func ) {
		if( obj->query("skill_type") )
			dest = present("weapon shelf",environment(me));
		else if(obj->query("armor_type") )
			dest = present("equip shelf",environment(me));
		else dest = present("item shelf",environment(me));
	}
        if( obj->move(dest) )
        {
                message_vision( sprintf("$N將一%s%s放進%s。\n",
                        obj->query("unit"), obj->name(), dest->name()),
                        me );
                if(dest->query("access_log")) log_file("access_log",sprintf("[%s] %s put %s in %s\n",ctime(time()),me->name_id(1),obj->name(),dest->short()));
                return 1;
        }
        else return 0;
}
