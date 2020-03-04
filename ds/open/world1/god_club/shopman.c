#include <ansi.h>
inherit NPC;
int do_sell_all(object me);
void create()
{
        set_name("怪叔叔",({"stranger of named charles","charles","seller"}));
        set("level",1);
        set("race","人類");
        set("age", 33);
        set("no_fight",1);
    set("long",HIW"愛去 Hotel 偷聽人辦事的"HIC"娃娃臉叔叔"HIW"，你打從心底覺得，他是個怪人。\n"NOR);
        setup();
}
void init()
{
        add_action("do_sell","sell");
}
int do_sell(string arg)
{
      object ob,me;
        int valu;
        me=this_player();

        if(!arg) return notify_fail("你要賣什麼東西？\n");
        if(arg=="all")
        {
                do_sell_all(me);
                return 1;
        }
        if(!ob=present(arg,me))
                return notify_fail("你沒有這樣東西。\n");
        valu=ob->query("value");
        if( ob->query("money_id") )
                return notify_fail("嗯..賣錢? 我不幫人洗錢的。\n");
        if( valu<20 )
                return notify_fail("這東西不值錢。\n");
        if( ob->query("secured") )
                return notify_fail("請先解除保存狀態。\n");
        if( ob->query("no_drop") )
                return notify_fail("這個東西很特別, 你還是自己保管好了。\n");
        if( ob->query("no_sell") )
                return notify_fail("我不收購這種東西。\n");
        if( ob->is_character() ) 
                return notify_fail("我不收購活的東西。\n");
        if(ob->query("equipped") )
                return notify_fail("請先卸除下來好嗎？\n");
        arg = ob->query("id");

        valu = valu/3+random(valu/5);
        message_vision("$N以"+chinese_number(valu)+"的價錢，賣了一"+ob->query("unit")+ob->query("name")+"給怪叔叔。\n",me);
        valu-= valu/10;
        tell_object(me,"怪叔叔抽了一成佣金，並幫你匯了"+chinese_number(valu)+"到你的錢莊帳戶裡。\n");
        me->add("bank/past",valu);
                destruct(ob);
        me->save();
        return 1;
}
int do_sell_all(object me)
{
       object *inv;
       int i,money,cost;
        money=0;
        inv = all_inventory(me);
        for(i=0;i<sizeof(inv);i++)
        {
                if( inv[i]->query("value") < 20 ) continue;
                if( inv[i]->query("secured") ) continue;
                if( inv[i]->query("equipped") ) continue;
                if( inv[i]->query("money_id") ) continue;
                if( inv[i]->query("no_drop") ) continue;
                if( inv[i]->query("no_sell") ) continue;
                if( inv[i]->is_character() ) continue;
                cost=inv[i]->query("value")/3+random(inv[i]->query("value")/5);
                message_vision("  $N以"+chinese_number(cost)+"的價錢將"+inv[i]->name()+"賣給了$n。\n",me,this_object());
                money+=cost;
                destruct(inv[i]);
        }
        if(money<1)
        {
                tell_object(me,"  你沒有東西可以賣了。\n");
                return 1;
        }
        message_vision("\n$N這些東西總共以"+chinese_number(money)+"的價錢賣給怪叔叔。\n",me);
        money-= money/10;
        tell_object(me,"怪叔叔抽了一成佣金，並幫你匯了"+chinese_number(money)+"到你的錢莊帳戶裡。\n");
        me->add("bank/past",money);
        me->save();
        return 1;
}
