inherit ITEM;
#include <ansi.h>
void create()


{
        set_name(CYN"ＡＴＭ"HIC"自動轉帳機"NOR, ({"atm transfer machine", "machine"}));
        set("unit", "臺");
        set("long",HIW"一個破破的轉帳機器，指令格式為: transfer <數量> coin to 玩家ID"NOR);
        set_weight(999999);     
        set("no_get",1);
        set("no_sac",1);
        setup();
}
 
void init()
{

        add_action("do_transfer", "transfer");
}

int do_transfer(string arg)


{
        string from, usr;
        int amount;
        object from_ob, me, usr_ob;

        me = this_player();
        if( !arg || sscanf(arg, "%d %s to %s", amount, from, usr)!=3 )
                return notify_fail("指令格式﹕transfer <數量> coin to <玩家>\n");
	if( amount < 1 ) return notify_fail("你在洗錢喔•\n");
        usr_ob = LOGIN_D->find_body(usr);
        if( !usr_ob ) return notify_fail("沒有這個使用者\n");                
        from_ob = new("obj/money/"+from);
        if( me->query("bank/past") < amount) return notify_fail("你銀行裡沒有這麼多錢\n");
         tell_object(me, 
                "你將 "+HIY+ chinese_number(amount) + NOR+" "+from_ob->query("base_unit")+from_ob->query("name")+"匯給"+usr_ob->query("name")+"\n");
         tell_object(usr_ob,HIW"【"HIG"銀"NOR+GRN"行"HIG"通"NOR+GRN"知"HIW"】"NOR+me->query("name")+"匯給你 "+HIY+chinese_number(amount)+NOR+" "+from_ob->query("base_unit")+from_ob->query("name")+"\n");

        if( me->query("bank/past") == amount ) me->delete("bank/past"); 
        else me->add("bank/past", -amount);
        usr_ob->add("bank/past", amount);
        return 1;

}

