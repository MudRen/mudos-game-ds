#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"同行卡片"NOR, ({ "let's go card","card" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "張");
                set("long", "\n");
                set("value",0);
               }
        setup();
}

void init()
{
        add_action("do_move","move");
}

int do_move(string arg)
{
        object me,place,player,*obs;
        me = this_player();
        if( !arg )
          return notify_fail("用法: move 人(或房間)\n");
        if( player = find_player(arg) && player = find_living(arg) ){
        message_vision(HIC"使用同行！"HIY+player->query("name")+"！\n",me);
        obs = all_inventory(environment(me));
        for(int x=0; x<sizeof(obs);x++) {
                if( !userp(obs[x]) || !living(obs[x]))continue;
                message_vision(HIW"\n只見$N的身形被一陣光芒包圍後，便消失在空氣之中•\n"NOR,obs[x]);
                obs[x]->move(environment(player));
                }  
        } else if( file_size(arg)>0 ) {  
        place = load_object(arg);
        message_vision(HIC"使用同行！"NOR"前往"HIY+place->query("short")+"！\n",me);
        obs = all_inventory(environment(me));
        for(int x=0; x<sizeof(obs);x++) {
                if( !userp(obs[x]) || !living(obs[x]))continue;
                message_vision(HIW"\n只見$N的身形被一陣光芒包圍後，便消失在空氣之中•\n"NOR,obs[x]);
                obs[x]->move(place); 
                }        } else {
        tell_object(me,"沒有這個玩家或地方。\n");  
        }
        return 1;
}

