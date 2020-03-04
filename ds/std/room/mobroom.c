
/* -------------------------------------------------
  隨機怪物出現(踩地雷式)繼承檔 inherit MOBROOM;
  edit by luky 99.3.18
  修改 by wilfred 2000/9/29
 
   set("chance",50);         //則有 50% 的機率會出現怪物.
   set("mob_amount",3);      //則最多出現三個怪物.
   set_temp("stop_creat",1); //則停止出現怪物.
   set("mob_object",({       //設定怪物檔名.
   "/open/world2/anfernee/start/npc/bug",
   "/u/l/luky/npc/mosquito"
}));
   set("out_mob", 30); 在 clean_up 之前, 只會有 30 隻怪物出現
  ------------------------------------------------- */
#include <dbase.h>
#include <ansi.h>
#define MAX_MOB_AMOUNT 15
#define MAX_OUT_MOB 50

inherit ROOM;
void create()
{
    seteuid(getuid());
}

void init()
{
    object me;

    ::init();
    me = this_player();

    if( !userp(me) ) return;
    if( environment(me)->query_temp("stop_creat") )
        return;

    remove_call_out("creatmob");
    call_out("creatmob", 2, me);
}

int getLimit()
{
    int limit = query("mob_amount");
    if( limit > MAX_MOB_AMOUNT )
        limit = MAX_MOB_AMOUNT;
    if( limit < 1 )
        limit = 1;
    return limit;
}

int getChance()
{
    int chance = query("chance");
    if( chance > 100 )
        chance = 100;
    if( chance < 1   )
        chance = 1;
    return chance;
}

int getOutmob()
{
    return (query("out_mob"))? query("out_mob") : MAX_OUT_MOB;
}

void creatmob(object me)
{
    int chance, limit, amount=0, i;
    string file;
    mapping mob_list;
    object c_mob, *inv;
    mixed *mob;

    if( !me || environment(me) != this_object() )
        return;
    if( query_temp("out_mob") >= getOutmob() )
        return;

    limit = getLimit();
    chance = getChance();

    if( arrayp(mob_list = query("mob_object")) )
    {
        for(i=0; i<sizeof(mob_list); i++)
        {
            file = mob_list[i]+".c";
                        if( mob = filter_array(children(file), (: clonep :)) )
                amount += sizeof(mob);
        }
    }
    else
    {
        if( !random(4) )
            tell_room(this_object(),"這裡似乎有些風吹草動。\n");
        return;
    }

    if(amount > limit)
    {
        if( !random(3) )
            tell_room(this_object(),"這裡似乎有些風吹草動。\n");
        return;
    }

    inv = all_inventory(this_object());

    if( arrayp(mob_list = query("mob_object")) && sizeof(inv) <= limit)
    {
        file = mob_list[random(sizeof(mob_list))]+".c";
        if( random(100) <= chance )
        {
            c_mob = new_ob(file);
            if(!c_mob)
            {
                log_file("mobroom", sprintf("[%s] %s creatmob %s fail.\n",ctime(time()),file, base_name(this_object())));
                return;
            }
            c_mob->move(this_object());
            c_mob->set("startroom", base_name(this_object()));
            tell_room(this_object(),"附近突然出現了一" +c_mob->query("unit")+c_mob->query("name")+ "。\n");
            set_temp("out_mob", query_temp("out_mob")+1);
        }
        else if( !random(3) )
            tell_room(this_object(),"這裡似乎有些風吹草動。\n");
    }
    else if( !random(4) )
        tell_room(this_object(),"這裡似乎有些風吹草動。\n");

    return;
}

