//inventory.c

#include <ansi.h>
#include <weapon.h>

inherit F_CLEAN_UP;
int sort_item(object ob1, object ob2);
int main(object me, string arg)
{
        int i,j;
        object *inv, ob;
        string str, show_durable;
        if( wizardp(me) && arg ) {
                ob = find_player(arg);
                if( !ob ) ob = present(arg, environment(me));
                if( !ob ) ob = find_living(arg);
                else if(!living(ob)) ob = find_living(arg);
        }

        if( !ob ) ob = me;

        inv = all_inventory(ob);
        inv = sort_array(inv, "sort_item", this_object());
        if( !sizeof(inv) )
        {
                write((ob==me)? "  目前你身上沒有任何東西。\n"
                        : "  " + ob->name() + "身上沒有攜帶任何東西。\n");
                return 1;
        }
        str=""; j=1;
        for(i=0; i<sizeof(inv); i++)
        {
          if( inv[i]->query_temp("riden") ) continue;
          if( inv[i]->query_temp("invis") ) continue;

          show_durable = "";
          if( inv[i]->query("secured"))         // 保存
                show_durable += HIC "Ｋ" NOR;
          if( inv[i]->query_autoload() )        // 可SAVE EQ
                show_durable += HBK "Ｓ" NOR;   

          if( inv[i]->query_unique() )        // daily eq
                show_durable += HIY "Ｄ" NOR;   
          if( inv[i]->query("enhance_times") )  // 有加過強化卷軸
                show_durable += sprintf( HIM "(%d/%d)" NOR, inv[i]->query("enhance_times"), ENHANCE_D->getMaxTimes() );


          if( inv[i]->query("skill_type") )
            show_durable += NOR+WHT"[狀況→"+inv[i]->query_durable()+"%]"NOR;

          if( i+1 < sizeof(inv) )
          {
                if( inv[i]->query("name") == inv[i+1]->query("name")
                 && inv[i]->query("secured") == inv[i+1]->query("secured")
                 && !inv[i+1]->query("equipped")
                 && !inv[i+1]->query_temp("has_light")
                 && !inv[i]->query_temp("no_combine")
                 && !inv[i+1]->query_temp("no_combine")
                 )
                {
                  if(inv[i]->query("equipped") || inv[i]->query_temp("has_light"))
                  {
                        str = sprintf("%s    %-34s %s %s\n",str,
                        inv[i]->item_describe(0),
                        show_durable,
                        wizardp(me)? base_name(inv[i]) : "" );
                  }     
                  else j++;
                }
                else
                {
                        str = sprintf("%s    %-34s %s %s\n",str,
                        j>1? chinese_number(j)+inv[i]->query("unit")+inv[i]->item_describe(0) : inv[i]->item_describe(0),
                        show_durable,
                        wizardp(me)? base_name(inv[i]) : "" );
                        j = 1;
                }
          }
          else
          {
                        str = sprintf("%s    %-34s %s %s\n",str,
                        j>1? chinese_number(j)+inv[i]->query("unit")+inv[i]->item_describe(0) : inv[i]->item_describe(0),
                        show_durable,
                        wizardp(me)? base_name(inv[i]) : "" );
                        j = 1;
          }
        }


        write(sprintf("    %s身上帶著下列這些東西﹕        ("HIY"負重:%d%%"NOR" / "HIY"空間:%d%%"NOR")\n"+
                "  ==================================[%d/%d]==[%d/%d]=========\n",
                (ob==me)? "你": ob->name(),
                ob->query_encumbrance() * 100 / ob->query_max_encumbrance(),
                ob->query_capacity() * 100 / ob->query_max_capacity() ,
                ob->query_encumbrance(),
                ob->query_max_encumbrance(),
                ob->query_capacity(),
                ob->query_max_capacity(),
                 ));
        str += "\n";
//          me->start_more(str);
          tell_object(me, str);

        return 1;
}

int sort_item(object ob1, object ob2)
{
        string file1,file2;
        file1=base_name(ob1);
        file2=base_name(ob2);
        if(file1==file2)
        {
                return getoid(ob2)-getoid(ob1);
        }
        return strcmp(file1,file2);
}

int help (object me)
{
        write(@HELP
指令格式: inventory
 
可列出你(妳)目前身上所攜帶的所有物品。
 
註 : 此指令可以 " i " 代替。
 
HELP
);
        return 1;
}


